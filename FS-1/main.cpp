#include <stdlib.h>
#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 16

int main(int argc, char** argv){
    if (argc < 2) {
        std::cerr << "file path is not provided" << std::endl;
        exit(1);
    }
    
    char* fileName = argv[1];
    int fileDescriptor = open(fileName, O_RDONLY);
    if (fileDescriptor < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    char* buffer = (char*)malloc(BUFFER_SIZE);
    
    while (true) {
        int readBytes = read(fileDescriptor, buffer, BUFFER_SIZE);
            
        if (readBytes < 0) {
            std::cerr << strerror(errno) << std::endl;
            exit(errno);
        }
            
        if (readBytes == 0) {
            break;
        }
            
        buffer[readBytes] = '\0';
        std::cout << buffer;
    }
    
    int closeResult = close(fileDescriptor);
    if (closeResult < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }    
    
    free(buffer);
    return 0;
}
