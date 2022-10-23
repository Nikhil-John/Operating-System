#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  system("clear");
  printf("\n\tDisk Scheduling Algorithm - FCFS\n\n");

  int num, request[100], total_head_movement = 0, initial;

  printf("Enter the number of requests: ");
  scanf("%d", &num);

  printf("Enter the request sequence: ");
  for (int i = 0; i < num; i++)
    scanf("%d", &request[i]);

  printf("Enter the initial head position: ");
  scanf("%d", &initial);

  for (int i = 0; i < num; i++) {
    total_head_movement += abs(request[i] - initial);
    initial = request[i];
  }

  printf("Total Head Movement is: %d\n\n", total_head_movement);

  return 0;
}
