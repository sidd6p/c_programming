#include <stdio.h>

struct inputs{
    int arrival_time;
    int waiting_time;
    int turn_arround_time;
    int brust_time;
    int temp_brust_time;
    int id;
};

int time , i = 0, j = 0, n = 0, t, total_waiting_time = 0, total_turn_arround_time = 0,  pre_brust = 0;
float average_waiting_time = 0.0, average_turn_around_time = 0.0;

void round_robin(struct inputs *process){
    process[0].waiting_time = 0;
    int j, i;
    for (j = 0; j < n; ){
             for(i = 0; i < n ;i++){
                if((process[i].arrival_time <= total_turn_arround_time) && (process[i].brust_time != -1)){
                process[i].waiting_time = pre_brust - process[i].arrival_time;
                process[i].waiting_time = (process[i].waiting_time > 0) ? process[i].waiting_time : 0;
                process[i].turn_arround_time = process[i].waiting_time + process[i].brust_time;
                total_turn_arround_time = total_turn_arround_time + process[i].turn_arround_time;
                total_waiting_time = total_waiting_time + process[i].waiting_time;
                process[i].waiting_time = (process[i].waiting_time > 0) ? process[i].waiting_time : 0;
                pre_brust += process[i].brust_time;
                process[i].brust_time = process[i].brust_time - time;
                }
                 if(process[i].brust_time <= 0){
                        j++;
                    process[i].brust_time = -1;
                }
        }

    }
}
int main()
{

printf("total number of process\n");
scanf("%d",&n);
printf("Enter timegap\n");
scanf("%d", &time);
struct inputs process[n];

for(i=0;i<n;i++)
{
 printf("\nBurst Time");
 scanf("\n %d",&process[i].brust_time);
 printf("\nArrival Time");
 process[i].temp_brust_time = process[i].brust_time;
 scanf("\n %d",&process[i].arrival_time);
 process[i].id = i;
 process[i].turn_arround_time = process[i].waiting_time = 0;
}

process[0].waiting_time = 0;
struct inputs t;

round_robin(process);

printf("Pid\tBurst time\t Arrival time\t WaitingTime\t Turn Arround Time\n");
for(i=0;i<n;i++){
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",process[i].id ,process[i].temp_brust_time, process[i].arrival_time, process[i].waiting_time,process[i].turn_arround_time);
}

average_waiting_time = (float)total_waiting_time / n;
average_turn_around_time = (float)total_turn_arround_time / n;
printf("\n\nAvg.Waiting Time: %f\nAvg.Turn Around Time: %f\n",average_waiting_time,average_turn_around_time);
return 0;
}




