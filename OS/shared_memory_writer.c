//SHM Write example..............
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>//file control options, For O_* constants 
#include <sys/stat.h> //data returned by the stat() function, For mode constants 
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
 
int main(){
    int shm_fd_writer, len_writer;
    void *addr_writer;
    char msg_writer[1024];
 
    shm_fd_writer = shm_open("Shm", O_RDWR | O_CREAT, 0666); //int shm_open(const char *name, int oflag, mode_t mode) open new or open an exitising POSIX shared memory object.
    if (shm_fd_writer == -1){
        perror("shm_open");
        exit(-1);
    }
    if (ftruncate(shm_fd_writer, 1024) == -1){ // int ftruncate(int fd, off_t len);
        perror("ftruncate");
        return -1;
    } 
    addr_writer = mmap(NULL, 1024, PROT_WRITE, MAP_SHARED, shm_fd_writer, 0); //  void *mmap(void *addr, size_t len, int prot, int flags,int fd, off_t offset);
    //The mmap() function is used for mapping between a process address space and either files or devices.
    //When a file is mapped to a process address space, the file can be accessed like an array in the program
    if (addr_writer == MAP_FAILED){
        perror("mmap");
        exit(-1);
    }
  strcpy(msg_writer,":)....I am siddhartha, 19bbs0072 and i study in VIT, how are you? I am good :)...");
  len_writer = strlen(msg_writer) + 1;
  memcpy(addr_writer, msg_writer, len_writer); //void *memcpy(void *dest, const void *src, size_t n) copies n characters from memory area src to memory area dest.
  printf("Wrote ...  %s   ...to the shared memory\n", msg_writer);
  return 0;
}