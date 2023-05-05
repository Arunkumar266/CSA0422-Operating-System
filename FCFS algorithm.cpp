#include <stdio.h>
#include <stdlib.h>

#define MAX_TRACKS 1000

int main() {
    int tracks[MAX_TRACKS];
    int num_tracks;
    int head_position;
    int total_head_movement = 0;
    int i;
    printf("Enter the number of tracks: ");
    scanf("%d", &num_tracks);
    printf("Enter the track positions: ");
    for (i = 0; i < num_tracks; i++) {
        scanf("%d", &tracks[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head_position);
    for (i = 0; i < num_tracks; i++) {
        total_head_movement += abs(tracks[i] - head_position);
        head_position = tracks[i];
    }
    printf("Average Head Movement: %.2f\n", (float) total_head_movement / num_tracks);

    return 0;
}

