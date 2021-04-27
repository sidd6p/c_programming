#include<stdio.h>
#include<string.h>

#define MAX_PARTITION 1000
#define MAX_PROCESS 1000

int total_part, total_proc, part_size[MAX_PARTITION], process_size[MAX_PROCESS];

void input();
void first_fit();
void best_fit();
void worst_fit();

int main(){
    int choice = -1;
    input();
    printf("\nSelect the method:\n1-) First fit\n2-) Best fit\n3-) Worst fit\n");
    scanf("%d", &choice);
    printf("\n");
    switch(choice){
        case 1:
        first_fit();
        break;
        case 2:
        best_fit();
        break;
        case 3:
        worst_fit();
        break;
        default:
        printf("INVALID CHOICE\n");
        break;
    }
    return 0;
}

void input(){
    printf("Enter total number of PARTITION\n");
    scanf("%d", &total_part);
    for(int i = 0; i < total_part; i++){
        printf("Enter size of PARTITION %d\t", i + 1);
        scanf("%d", &part_size[i]);
    }
    printf("Enter total number of PROCESS\n");
    scanf("%d", &total_proc);
    for(int i = 0; i < total_proc; i++){
        printf("Enter size of PROCESS %d\t", i + 1);
        scanf("%d", &process_size[i]);
    }
}

void first_fit(){
    int j = 0;
    int flag = 1;
    for(int i = 0; i < total_proc; i++){
        flag = 1;
        for(j = 0; j < total_part; j++){
            if(process_size[i] <= part_size[j] && flag == 1){
                part_size[j] = part_size[j] - process_size[i];
                printf("Process %d is allocated in partition %d\n", i + 1, j + 1);
                printf("Memory space available\n");
                for(int k = 0; k < total_part; k++){
                    printf("Partion %d --> %dkb\n", k + 1, part_size[k]);
                }
                flag = -1;
                break;
            }
        }
        if(j == total_part){
            printf("Not sufficient Memory space to accomadate PROCESS %d\n", i + 1);
            return;
        }
    }
}

void worst_fit(){
    int j = 0;
     for(int i = 0; i < total_proc; i++){
        int flag = -1;
        int temp[total_part];
        memcpy(temp, part_size, sizeof(temp));
        int max = -1;
        for(j = 0; j < total_part; j++){
            if(process_size[i] <= temp[j]){
                temp[j] = temp[j] - process_size[i];
                       if(max < temp[j]){
                        max = temp[j];
                       flag = j;
               }
            }
        }
        if(flag == -1){
            printf("Not sufficient Memory space to accomadate PROCESS %d\n", i + 1);
            return;
        }
        else{
            printf("Process %d is allocated in partition %d\n", i + 1, flag + 1);
            part_size[flag] = part_size[flag] - process_size[i];
            printf("Memory space available\n");
            for(int k = 0; k < total_part; k++){
                printf("Partion %d --> %dkb\n", k + 1, part_size[k]);
            }
        }
        
    }
}

void best_fit(){
    int j = 0;
     for(int i = 0; i < total_proc; i++){
        int flag = -1;
        int temp[total_part];
        memcpy(temp, part_size, sizeof(temp));
        int min = 99999;
        for(j = 0; j < total_part; j++){
            if(process_size[i] <= temp[j]){
                temp[j] = temp[j] - process_size[i];
                if(min >= temp[j]){
                    min = temp[j];
                    flag = j;
               }
            }
        }
        if(flag == -1){
            printf("Not sufficient Memory space to accomadate PROCESS %d\n", i + 1);
            return;
        }
        else{
            printf("Process %d is allocated in partition %d\n", i + 1, flag + 1);
            part_size[flag] = part_size[flag] - process_size[i];
            printf("Memory space available\n");
            for(int k = 0; k < total_part; k++){
                printf("Partion %d --> %dkb\n", k + 1, part_size[k]);
            }
        }
        
    }
}