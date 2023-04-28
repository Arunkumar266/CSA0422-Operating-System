#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int pages[] = {4, 1, 2, 4, 3, 2, 1, 5};
    int n = sizeof(pages) / sizeof(int);
    int frames[MAX_FRAMES];
    int page_faults = 0;
    int next_frame = 0;
    int i, j, k;
    int found;
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frames[next_frame] = pages[i];
            next_frame = (next_frame + 1) % MAX_FRAMES;
            page_faults++;
        }
        printf("Current frames: ");
        for (k = 0; k < MAX_FRAMES; k++) {
            if (frames[k] == -1) {
                printf("-");
            } else {
                printf("%d", frames[k]);
            }
            if (k < MAX_FRAMES - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", page_faults);

    return 0;
}
