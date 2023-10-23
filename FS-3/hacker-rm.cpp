#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "file path is not provided" << std::endl;
		exit(1);
	}

	char* fileName = argv[1];
	int fileDescriptor = open(fileName, O_TRUNC);
	if (fileDescriptor < 0) {
		std::cerr << strerror(errno) << std::endl;
		exit(errno);
	}
	
	off_t fileSize = lseek(fileDescriptor, 0, SEEK_END);
	char a = '\0';
	for(off_t i = 0; i < fileSize; i++) {
		if (write(fileDescriptor, &a, 1) == -1) {
            close(fileDescriptor);
            exit(errno);
        }
	}

	if (unlink(fileName) < 0) {
        std::cerr << strerror(errno) << std::endl;
		exit(errno);
    }

	close(fileDescriptor);

	return 0;
}
