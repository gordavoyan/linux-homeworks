#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/times.h>

void do_command(char** argv) {
    struct tms start, end;

    clock_t startTime, endTime;

    startTime = times(&start);

    pid_t pid = fork();

    if (pid == -1) {
        std::cerr << "Fork failed." << std::endl;
        exit(1);
    } else if (pid == 0) {
        int result = execvp(argv[0], argv);

        if (result == -1) {
            std::cerr << "Execution failed.";
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
        endTime = times(&end);

        int exited = WIFEXITED(status);
        if (exited) {
            double duration = (double)(endTime - startTime) / sysconf(_SC_CLK_TCK);
            std::cout << "Completed with " << exited << " exit code and took "<< duration << " seconds.";
        } else {
            std::cerr << "Command did't complete.";
            exit(1);
        }
    }
}

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cerr << "Command not provided";
        return 1;
    }

    do_command(argv + 1);

    return 0;
}
