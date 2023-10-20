#include <stdlib.h>
#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 16

int main(int argc, char** argv) {

    if (argc < 3) {
        std::cerr << "source and destination file path is not provided correctly" << std::endl;
        exit(1);
    }
	
    const char* source = argv[1];
    int sourceFileDescriptor = open(source, O_RDONLY);
    if (sourceFileDescriptor < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    const char* destination = argv[2];
    int destinationFileDescriptor = open(destination, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
    if (destinationFileDescriptor < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }

    char* buffer = (char*)malloc(BUFFER_SIZE);
    long allBytes = 0;
    long readBytes = 0;

    while(true){
        readBytes = read(sourceFileDescriptor, buffer, BUFFER_SIZE);
        if(readBytes < 0){
            std::cerr << strerror(errno) << std::endl;
            exit(errno);
        }

        if(readBytes == 0){
            break;
        }

        allBytes += readBytes;
        long writeBytes = write(destinationFileDescriptor, buffer, readBytes);

        if(writeBytes < 0){
            std::cerr << strerror(errno) << std::endl;
            exit(errno);
        }
    }

    int sourceCloseResult = close(sourceFileDescriptor);
    if (sourceCloseResult < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }  
    int destinationCloseResult = close(destinationFileDescriptor);
    if (destinationCloseResult < 0) {
        std::cerr << strerror(errno) << std::endl;
        exit(errno);
    }   

    free(buffer);
    return 0;
}