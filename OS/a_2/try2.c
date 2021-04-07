#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

char* formatdate(char* str, time_t val);
int main(){

    DIR *dir;
    struct stat info;
    struct dirent *entry;
    int file=0;
    char date[36];
    time_t second;
    second = time(NULL);

    system("ls -la");

    printf("\n\nfiles not accessed since last week are:\n\n");
    if((dir = opendir(".")) == NULL){
        perror("Opendir() error");
    }
     else{

        while((entry = readdir(dir)) != NULL){
           if((file=open(entry->d_name,O_RDONLY)) < -1){
                perror("file discriptor");
            }
            else{
            if(fstat(file, &info) < 0){
                perror("fstat error");
            }
            else{

                    if((second - info.st_atime) < 604800){
                         printf(" file is %s and last accessed at %s\n", entry->d_name, formatdate(date, info.st_atime));
                    }
              }
        }

    }
     closedir(dir);
  }
    return 0;
}
char* formatdate(char* str, time_t val){
    strftime(str, 36, "%d.%m.%Y", localtime(&val));
    return str;
}


