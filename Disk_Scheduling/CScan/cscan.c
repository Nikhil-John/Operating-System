#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  system("clear");
  printf("\n\tDisk Scheduling Algorithm - Scan\n\n");

  int disk_size, num, head, initial, temp, request[100], sorted_request[100];
  int i, j, total_head_movement = 0;

  printf("Enter the size of the disk: ");
  scanf("%d", &disk_size);

  printf("Enter the number of requests: ");
  scanf("%d", &num);

  printf("Enter the initial head position: ");
  scanf("%d", &head);

  printf("Enter the request sequence: ");
  for (i = 0; i < num; i++)
    scanf("%d", &request[i]);

  initial = head;

  for (i = 0; i < num - 1; i++) {
    for (j = 0; j < num - i - 1; j++) {
      if (request[j] > request[j + 1]) {
        temp = request[j];
        request[j] = request[j + 1];
        request[j + 1] = temp;
      }
    }
  }

  int mid;
  for (i = 0; i < num; i++) {
    if (initial < request[i]) {
      mid = i;
      break;
    }
  }

  i = 0;

  for (j = mid; j < num; j++, i++)
    sorted_request[i] = request[j];

  sorted_request[i] = disk_size - 1;
  i++;
  sorted_request[i] = 0;
  i++;

  for (j = 0; j <= mid - 1; j++, i++)
    sorted_request[i] = request[j];

  printf("\nExecution sequence\n");
  printf("%d ", head);

  for (i = 0; i <= num + 1; i++) {
    total_head_movement += abs(sorted_request[i] - initial);
    initial = sorted_request[i];
    printf("%d ", sorted_request[i]);
  }

  printf("\n");

  printf("Total Head Movement is: %d\n\n", total_head_movement);

  return 0;
}
