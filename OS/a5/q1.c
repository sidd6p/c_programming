#include<stdio.h>
#include<string.h>

#define MAX_RES 100//maximum resource type
#define MAX_PRO 100//maximum number of process

int resource_type = 0, resource[MAX_RES], process_total = 0, seq[MAX_PRO];
int  process_alc[MAX_PRO][MAX_RES], process_max[MAX_PRO][MAX_RES];
int  available[MAX_RES], work[MAX_RES], need[MAX_PRO][MAX_RES], finish[MAX_PRO];

void input_data();
void safety_algorith();
void request_algorith();

int main(){
    printf("Banker's Algorithm\n\n");
    input_data();
    safety_algorith();
    return 0;
}

void safety_algorith(){
    int flag[process_total], h = 0, l = process_total;
    for(int a = 0; a < l; a++){
        int i = (a % process_total);
        for(int j = 0; j < resource_type; j++){
            if(need[i][j] > work[j]){
                flag[i] = -1;
            }
        }
        if(finish[i] == 1){
            l += l;
            break;
        }
        if(flag[i] == -1){
            break;
        }
        for(int j = 0; j < resource_type; j++){
            work[j] += process_alc[i][j];
        }
        finish[i] = 1;
        seq[h++] = i;

    }
    for(int i = 0; i < resource_type; i++){
        printf("%d\t", work[i]);
    }
    for(int i = 0; i < process_total; i++){
        if(finish[i] == -1){
            printf("DEADLOCK EXITS\n");
            return;
        }
    }
    printf("NO DEADLOCK EXIT\nSequence of execurion can be\n");
    for(int i = 0; i < process_total; i++){
        printf("Process %d\t", seq[i] + 1);
    }
}

void input_data(){
    printf("Input the following data\n");
    printf("Enter total type of resource\n");
    scanf("%d", &resource_type);
    for(int i = 0; i < resource_type; i++){
        printf("Total number of instances for resource %d\n", i + 1);
        scanf("%d", &resource[i]);
        available[i] = resource[i];
    }
    printf("Enter total number of process\n");
    scanf("%d", &process_total);
    for(int i = 0; i < process_total; i++){
        finish[i] = -1;// using -1 to indicate false
        printf("\nEnter max resource for PROCESS %d\n", i + 1);
        for(int j = 0; j < resource_type; j++){
            scanf("%d", &process_max[i][j]);
        }
    }
    for(int i = 0; i < process_total; i++){
        printf("\nEnter allocated resource for PROCESS %d\n", i + 1);
        for(int j = 0; j < resource_type; j++){
            scanf("%d", &process_alc[i][j]);
            available[j] -= process_alc[i][j];
            need[i][j] = process_max[i][j] - process_alc[i][j];
        }
    }
    memcpy(work, available, sizeof(work));//work = available
    printf("Total available reouces are \n");
    for(int i = 0; i < resource_type; i++){
        printf("%d\n", work[i]);
    }
    for(int i = 0; i < process_total; i++){
        printf("Need for process %d-->\t", i + 1);
        for(int j = 0; j < resource_type; j++){
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }
}