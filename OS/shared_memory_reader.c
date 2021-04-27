//SHM Read Example
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
 
int main()
{
    int res, shm_fd, len;
    void *addr;
    char msg[100];
 
    shm_fd = shm_open("Shm1", O_RDONLY | O_CREAT, 0666);
    if (shm_fd == -1)
    {
        perror("shm_open");
        return -1;
    }

        addr = mmap(NULL, 1024, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (addr == MAP_FAILED)
    {
        perror("mmap");
        return -1;
    }
  //strcpy(msg,"We are in OS lab");
 // len = strlen(msg) + 1;
    memcpy(msg, addr, 25);
    printf("Read from shared memory: %s\n",  msg);
    return 0;
}