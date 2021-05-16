//SHM Write example..............
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
 
int main(){
    int res, shm_fd, len;
    void *addr;
    char msg[100];
 
    shm_fd = shm_open("Shm1", O_RDWR | O_CREAT, 0666);
    if (shm_fd == -1){
        perror("shm_open");
        return -1;
    }
    if (ftruncate(shm_fd, 1024) == -1){
        perror("ftruncate");
        return -1;
    } 
    addr = mmap(NULL, 1024, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (addr == MAP_FAILED){
        perror("mmap");
        return -1;
    }
  strcpy(msg,"We are in OS lab");
  len = strlen(msg) + 1;
  memcpy(addr, msg, len);
  printf("Wrote ...  %s   ...to the shared memory\n", msg);
  //shm_unlink("Shm1");
    return 0;
}