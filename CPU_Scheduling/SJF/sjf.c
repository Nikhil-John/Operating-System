#include <stdio.h>
#include <stdlib.h>

// Non preemptive SJF
// Program assumes that the arrival time of all processes is 0

struct sjf {
  int burst_time, wait_time, turn_around_time, completion_time;
} s[30];

int main(int argc, char *argv[]) {
  system("clear");
  printf("\n\t\tCPU Scheduling Algorithm - Non Preemptive SJF\n\n");

  int num, temp;
  float avg_tat = 0.0, avg_wt = 0.0;

  printf("Enter the number of processes: ");
  scanf("%d", &num);

  // Entering the burst time of each processes
  printf("Enter the burst time of each of the process\n\n");
  for (int i = 0; i < num; i++) {
    printf("Process [%d]\n", i + 1);
    printf("Burst Time: ");
    scanf("%d", &s[i].burst_time);
    printf("\n");
  }

  // Sorting the processes based on their burst time
  for (int i = 0; i < num - 1; i++) {
    for (int j = 0; j < num - i - 1; j++) {
      if (s[j].burst_time > s[j + 1].burst_time) {
        temp = s[j].burst_time;
        s[j].burst_time = s[j + 1].burst_time;
        s[j + 1].burst_time = temp;
      }
    }
  }

  // Turn Around Time = Completion Time - Arrival Time
  // Waiting Time = Turn Around Time - Burst Time

  s[0].wait_time = 0; // waiting time of the first process is 0
  s[0].turn_around_time = s[0].burst_time;
  s[0].completion_time = s[0].burst_time;
  int total_tat = s[0].turn_around_time, total_wt = s[0].wait_time;

  for (int i = 1; i < num; i++) {
    s[i].completion_time = s[i].burst_time + s[i - 1].completion_time;
    s[i].turn_around_time = s[i].completion_time;
    s[i].wait_time = s[i].turn_around_time - s[i].burst_time;
    total_tat += s[i].turn_around_time;
    total_wt += s[i].wait_time;
  }

  avg_tat = (float)total_tat / num;
  avg_wt = (float)total_wt / num;

  printf("Burst Time\tTurn Around Time\t  Waiting Time\n");
  for (int i = 0; i < num; i++)
    printf("%d\t\t\t%d\t\t\t%d\n", s[i].burst_time, s[i].turn_around_time,
           s[i].wait_time);
  printf("Average Turn Around Time: %f\n", avg_tat);
  printf("Average Waiting Time: %f\n\n", avg_wt);

  return 0;
}
