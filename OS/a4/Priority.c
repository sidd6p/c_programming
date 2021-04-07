#include <stdio.h>
#define MAXPROCESS 1000

struct inputs{
    int arrival_time;
    int waiting_time;
    int turn_arround_time;
    int brust_time;
    int priority;
    int id;
};

int i = 0, j = 0, n = 0, t, total_waiting_time = 0, total_turn_arround_time = 0, pre_wait = 0, pre_brust = 0;
float average_waiting_time = 0.0, average_turn_around_time = 0.0;

void fcfs(struct inputs *process){
    process[0].waiting_time = 0;
    int j, i;
    for (j = 0; j < n; ){
        for(i = 0; i < n ;i++){
            if((process[i].arrival_time <= total_turn_arround_time) && (process[i].turn_arround_time == 0)){
                process[i].waiting_time = pre_brust - process[i].arrival_time;
                process[i].waiting_time = (process[i].waiting_time > 0) ? process[i].waiting_time : 0;
                process[i].turn_arround_time = process[i].waiting_time + process[i].brust_time;
                total_turn_arround_time = total_turn_arround_time + process[i].turn_arround_time;
                total_waiting_time = total_waiting_time + process[i].waiting_time;
                pre_brust += process[i].brust_time;
                pre_wait = process[i].waiting_time;
                j++;
            }
        }

    }
}
int main()
{

printf("total number of process\n");
scanf("%d",&n);
struct inputs process[n];

for(i=0;i<n;i++)
{
 printf("\n\nBurst Time for process %d===>", i+ 1);
 scanf("\t %d",&process[i].brust_time);
 printf("\nArrival Time for process %d===>", i + 1);
 scanf("\t%d",&process[i].arrival_time);
 printf("\nPriority for process %d===>", i + 1);
 scanf("\t%d",&process[i].priority);
 process[i].id = i;
 process[i].turn_arround_time = process[i].waiting_time = 0;
}
process[0].waiting_time = 0;
struct inputs t;

for (i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if (process[i].priority > process[j].priority ){
            t = process[j];
            process[j] = process[i];
            process[i] = t;

        }
    }
}
fcfs(process);

printf("Process_ID\tBurst time\t Arrival time\t WaitingTime\t Turn Arround Time\n");
for(i=0;i<n;i++){
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",process[i].id, process[i].brust_time, process[i].arrival_time, process[i].waiting_time,process[i].turn_arround_time);
}

average_waiting_time = (float)total_waiting_time / n;
average_turn_around_time = (float)total_turn_arround_time / n;
printf("\n\nAvg.Waiting Time: %f\nAvg.Turn Around Time: %f\n",average_waiting_time,average_turn_around_time);
}




