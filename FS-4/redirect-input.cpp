#include <iostream>
#include <string>
#include <algorithm>
#include <fcntl.h>
#include <unistd.h>

void initialize(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "file path is not provided" << std::endl;
		exit(1);
    }

    const char* fileName = argv[1];
    int fd = open(fileName, O_RDONLY);

    if (fd < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(1);
    }

    if (dup2(fd, 0) == -1) {
        std::cerr << strerror(errno) << std::endl;
        exit(1);
    }
}

int main(int argc, char** argv) {
    initialize(argc, argv);

    std::string input;
    std::cin >> input;

    std::string reversed = input;

    std::reverse(reversed.begin(), reversed.end());

    std::cout << reversed << std::endl;

    return 0;
}
