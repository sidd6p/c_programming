//SHM Read Example
#include <stdio.h>
#include <sys/mman.h>//memory management declarations
#include <fcntl.h>//file control options, For O_* constants 
#include <sys/stat.h> //data returned by the stat() function, For mode constants 
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
 
int main(){
    int shm_fd_reader;
    void *addr_reader;
    char msg[1024];
 
    shm_fd_reader = shm_open("Shm", O_RDONLY | O_CREAT, 0666); //int shm_open(const char *name, int oflag, mode_t mode); open new or open an exitising POSIX shared memory object
    if (shm_fd_reader == -1){
        perror("shm_open");
        exit(-1);
    }
    addr_reader = mmap(NULL, 1024, PROT_READ, MAP_SHARED, shm_fd_reader, 0); // void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
    //The mmap() function is used for mapping between a process address space and either files or devices.
    // When a file is mapped to a process address space, the file can be accessed like an array in the program
    if (addr_reader == MAP_FAILED){
        perror("mmap");
        exit(-1);
    }
    memcpy(msg, addr_reader, 1024); //void *memcpy(void *dest, const void *src, size_t n) copies n characters from memory area src to memory area dest.
    printf("Read from shared memory: %s\n",  msg);
    shm_unlink("Shm");
    return 0;
}

/*int shm_open(const char *name, int oflag, mode_t mode);
The oflag argument is the bitwise-inclusive OR of the lags defined in the <fcntl.h> header. 
If successful, shm_open() shall return a file descriptor for the shared memory object.
The open file description is new, and therefore the file descriptor does not share it with any other processes.  */