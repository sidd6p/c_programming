#include <stdio.h>

struct inputs{
    int arrival_time;
    int waiting_time;
    int turn_arround_time;
    int burst_time;
    int temp_burst_time;
    int id;
};


int i = 0, j = 0, n = 0, t, total_waiting_time = 0, total_turn_arround_time = 0, time = 0, count = 0, smallest = 0, end = 0;
float average_waiting_time = 0.0, average_turn_around_time = 0.0;


int main()
{
printf("total number of process\n");
scanf("%d",&n);
struct inputs process[n];

for(i=0;i<n;i++)
{
 printf("\n\nBurst Time for process %d===>", i+ 1);
 scanf("\t %d",&process[i].burst_time);
 process[i].temp_burst_time = process[i].burst_time;
 printf("\nArrival Time for process %d===>", i + 1);
 scanf("\t%d",&process[i].arrival_time);
 process[i].id = i;
 process[i].turn_arround_time = process[i].waiting_time = 0;
 process[i].id = i + 1;
}
      process[i].burst_time = 1000;
      for(time = 0; count != n; time++)
      {
            smallest = i;
            for(i = 0; i < n; i++)
            {
                  if(process[i].arrival_time <= time && process[i].burst_time < process[smallest].burst_time && process[i].burst_time > 0)
                  {
                        smallest = i;
                  }
            }
            process[smallest].burst_time--;
            if(process[smallest].burst_time == 0)
            {
                  count++;
                  end = time + 1;
                  process[smallest].waiting_time = end - process[smallest].arrival_time- process[smallest].temp_burst_time;
                  total_waiting_time +=  process[smallest].waiting_time;
                  process[smallest].turn_arround_time =  end - process[smallest].arrival_time;
                  total_turn_arround_time += process[smallest].turn_arround_time;
            }
      }
printf("PID\t Burst time\t Arrival time\t WaitingTime\t Turn Arround Time\n");
for(i=0;i<n;i++){
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",process[i].id, process[i].temp_burst_time, process[i].arrival_time, process[i].waiting_time,process[i].turn_arround_time);
}

average_waiting_time = (float)total_waiting_time / n;
average_turn_around_time = (float)total_turn_arround_time / n;
printf("\n\nAvg.Waiting Time: %f\nAvg.Turn Around Time: %f\n",average_waiting_time,average_turn_around_time);
return 0;
}
