#include <stdio.h>
#define P 3 
#define R 3 
int main()
{
    int max[P][R] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};
    int allocation[P][R] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};
    int available[R] = {1, 2, 0};
    int need[P][R];
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    int finish[P] = {0};
    int work[R];
    for (int i = 0; i < R; i++) {
        work[i] = available[i];
    }

    int safe_seq[P];
    int count = 0;
    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < R; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == R) {
                    for (int k = 0; k < R; k++) {
                        work[k] += allocation[i][k];
                    }
                    safe_seq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            break;
        }
    }
    if (count < P) {
        printf("System is in a deadlock state.\n");
        printf("Deadlocked processes are: ");
        for (int i = 0; i < P; i++) {
            if (finish[i] == 0) {
                printf("%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("System is not in a deadlock state.\n");
    }

    return 0;
}

