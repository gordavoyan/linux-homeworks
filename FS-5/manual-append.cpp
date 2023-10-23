#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "file path not provided" << std::endl;
        exit(errno);
    }

    char* fileName = argv[1];
    int fd1, fd2;

    fd1 = open(fileName, O_WRONLY | O_CREAT | O_TRUNC);
    if (fd1 < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    fd2 = dup(fd1);

    if (fd2 < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    int firstLineBytes = 11;
    int secondLineBytes = 12;
    write(fd1, "first line\n", firstLineBytes);
    write(fd2, "second line\n", secondLineBytes);

    close(fd1);
    close(fd2);

    return 0;
}
