//Siddhartha Purwar 27-April-2021
//Banker algorithm
//Safety algorithm and Request algorithm
#include<stdio.h>
#include<string.h>

#define MAX_RES 100//maximum number of resource type
#define MAX_PRO 100//maximum number of process

int resource_type = 0, process_total = 0;
int seq[MAX_PRO], finish[MAX_PRO], available[MAX_RES], temp_work[MAX_RES], work[MAX_RES], resource[MAX_RES];
int process_alc[MAX_PRO][MAX_RES], process_max[MAX_PRO][MAX_RES], need[MAX_PRO][MAX_RES];

void input_data();
void safety_algorithm();
void request_algorithm();

int main(){
    printf("Banker's Algorithm\n\n");
    input_data();
    safety_algorithm();
    request_algorithm();
    return 0;
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

void safety_algorithm(){
    int flag[process_total], h = 0, l = process_total;
    int temp_work[MAX_RES];
    memcpy(temp_work, work, sizeof(temp_work));
    for(int i = 0; i < process_total; i++){
        finish[i] = -1;// using -1 to indicate false
    }
    for(int a = 0; a < l; a++){
        int i = (a % process_total);
        for(int j = 0; j < resource_type; j++){
            if(need[i][j] > temp_work[j]){
                flag[i] = -1;
                break;
            }
            flag[i] = 1;
        }
        if(finish[i] == 1){
            continue;
        }
        if(flag[i] == -1){
            continue;
        }
        for(int j = 0; j < resource_type; j++){
            temp_work[j] += process_alc[i][j];
        }
        printf("\ntemp_work -->\t");
        for(int q = 0; q < resource_type; q++){
        printf("%d\t", temp_work[q]);
        }
        l += process_total;
        finish[i] = 1;
        seq[h++] = i;

    }
    for(int i = 0; i < process_total; i++){
        if(finish[i] == -1){
            printf("\nDEADLOCK EXITS\n");
            return;
        }
    }
    printf("\nNO DEADLOCK EXIT\nSequence of execurion can be\n");
    for(int i = 0; i < process_total; i++){
        printf("Process %d\t", seq[i] + 1);
    }
    printf("\n");
    return;
}

void request_algorithm(){
    int reques_id = -1, request[resource_type];
    printf("\nEnter the Requesting Process Number (%d....%d)\t", 0, process_total - 1);
    scanf("%d", &reques_id);
    printf("\nEnter requested resources\n");
    for(int i = 0; i < resource_type; i++){
        scanf("%d", &request[i]);
        if(request[i] > need[reques_id][i]){
            printf("\nCannot accept the request [Error: REQUEST is more than NEED]");
            return;
        }
        if(request[i] > available[i]){
            printf("\nCannot accept the request [Error: REQUEST is more than AVAILABLE]");
            return;
        }
    }
     for(int i = 0; i < resource_type; i++){
        available[i] -= request[i];
        process_alc[reques_id][i] += request[i];
        need[reques_id][i] -= request[i];
    }
     memcpy(work, available, sizeof(work));
     safety_algorithm();

}

