#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int num_tracks = 9;
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int head_pos = 50;
    int total_head_movement = 0;
    int i;

    // Calculate head movement for each track
    for(i = 0; i < num_tracks; i++)
    {
        total_head_movement += abs(tracks[i] - head_pos);
        head_pos = tracks[i];
    }

    // Print the average head movement
    printf("Average Head Movement: %.2f\n", (float)total_head_movement / num_tracks);

    return 0;
}
