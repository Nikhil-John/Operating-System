#include <stdio.h>
#include <stdlib.h>

// Round Robin

struct roundrobin {
  int arrival_time, burst_time, wait_time, turn_around_time, completion_time;
} s[30];

int main(int argc, char *argv[]) {
  system("clear");
  printf("\n\t\tCPU Scheduling Algorithm - Round Robin\n\n");

  int num, n, temp, temp1, temp_arr[30], time_quantum, sum = 0, count = 0;
  int total_tat=0, total_wt=0;
  float avg_tat = 0.0, avg_wt = 0.0;

  printf("Enter the number of processes: ");
  scanf("%d", &num);
  n = num;

  // Entering the arrival time and burst time of each processes
  printf("Enter the arrival time and burst time of each of the process\n\n");
  for (int i = 0; i < num; i++) {
    printf("Process [%d]\n", i + 1);
    printf("Arrival Time: ");
    scanf("%d", &s[i].arrival_time);
    printf("Burst Time: ");
    scanf("%d", &s[i].burst_time);
    temp_arr[i] = s[i].burst_time;
    printf("\n");
  }

  printf("Enter the time quantum: ");
  scanf("%d", &time_quantum);

  // Sorting the processes based on their arrival time
  for (int i = 0; i < num - 1; i++) {
    for (int j = 0; j < num - i - 1; j++) {
      if (s[j].arrival_time > s[j + 1].arrival_time) {
        temp = s[j].arrival_time;
        s[j].arrival_time = s[j + 1].arrival_time;
        s[j + 1].arrival_time = temp;
        temp1 = s[j].burst_time;
        s[j].burst_time = s[j + 1].burst_time;
        s[j + 1].burst_time = temp1;
      }
    }
  }

  printf("Process No.\t\tBurst Time\t\tTurn Around Time\t\tWaiting Time\n");

  for (int i = 0, sum = 0; n != 0;) {
    if (temp_arr[i] <= time_quantum && temp_arr[i] > 0) {  // burst time is less than time quantum and more than 0
      sum += temp_arr[i];
      temp_arr[i] = 0;
      count = 1;
    } else if (temp_arr[i] > 0) {  // burst time is more than time quantum
      temp_arr[i] -= time_quantum;
      sum += time_quantum;
    }
    if (temp_arr[i] == 0 && count == 1) {  // this condition indicates that the process has been used completely
      n--;
      printf("Process [%d]\t\t%d\t\t\t\t%d\t\t\t    %d\n", i + 1,
             s[i].burst_time, sum - s[i].arrival_time,
             sum - s[i].arrival_time - s[i].burst_time);
      total_wt = total_wt + sum - s[i].arrival_time - s[i].burst_time;
      total_tat = total_tat + sum - s[i].arrival_time;
      count = 0;
    }
    if (i == num - 1)
      i = 0;
    else if (s[i + 1].arrival_time <= sum)
      i++;
    else
      i = 0;
  }

  avg_tat = (float)total_tat / num;
  avg_wt = (float)total_wt / num;

  printf("Average Turn Around Time: %f\n", avg_tat);
  printf("Average Waiting Time: %f\n\n", avg_wt);

  return 0;
}
