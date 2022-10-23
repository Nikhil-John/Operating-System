#include <stdio.h>
#include <stdlib.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;
void input();
void show();
void calc();

int main(int argc, char *argv[]) {
  system("clear");
  printf("\n\t\tBanker's Algorithm\n\n");

  input();
  show();
  calc();

  printf("\n");

  return 0;
}

void input() {
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  printf("Enter the number of resource instances: ");
  scanf("%d", &r);

  printf("Enter the maximum matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < r; j++)
      scanf("%d", &max[i][j]);
  }

  printf("Enter the allocation matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < r; j++)
      scanf("%d", &alloc[i][j]);
  }

  printf("Enter the available resources:\n");
  for (int j = 0; j < r; j++) {
    scanf("%d", &avail[j]);
  }
}

void show() {
  printf("Process\tAllocation\tMax\tAvailable\n");

  for (int i = 0; i < n; i++) {
    printf("\nP[%d]\t", i + 1);

    for (int j = 0; j < r; j++)
      printf("%d ", alloc[i][j]);

    printf("\t\t");

    for (int j = 0; j < r; j++)
      printf("%d ", max[i][j]);

    printf("\t");

    if (i == 0) {
      for (int j = 0; j < r; j++)
        printf("%d ", avail[j]);
    }
  }
}

void calc() {
  int finish[100], ans[100], ind = 0;

  for (int i = 0; i < n; i++)
    finish[i] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < r; j++)
      need[i][j] = max[i][j] - alloc[i][j];
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      if (finish[i] == 0) {
        int flag = 0;
        for (int j = 0; j < r; j++) {
          if (need[i][j] > avail[j]) {
            flag = 1;
            break;
          }
        }
        if (flag == 0) {
          ans[ind++] = i;
          for (int y = 0; y < r; y++)
            avail[y] += alloc[i][y];
          finish[i] = 1;
        }
      }
    }
  }

  int flag = 1;

  for (int i = 0; i < n; i++) {
    if (finish[i] == 0) {
      flag = 0;
      printf("\nThe system is not in safe state\n\n");
      break;
    }
  }

  if (flag == 1) {
    printf("\nThe system is in safe state\n");
    printf("Safe sequence:\n");
    for (int i = 0; i < n - 1; i++)
      printf("P[%d] -> ", ans[i + 1]);
    printf("P[%d]", ans[n]);
  }
}
