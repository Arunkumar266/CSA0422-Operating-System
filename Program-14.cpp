#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num_frames = 3;
    int frames[num_frames];
    int num_pages = 19;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int page_faults = 0;
    int i, j, k;

    // Initialize frames array to -1 to indicate that it is empty
    for(i = 0; i < num_frames; i++)
        frames[i] = -1;

    // Iterate through all pages and check for page faults
    for(i = 0; i < num_pages; i++)
    {
        int page_found = 0;
        // Check if the current page is already in a frame
        for(j = 0; j < num_frames; j++)
        {
            if(frames[j] == pages[i])
            {
                page_found = 1;
                break;
            }
        }

        // If the current page is not in any frame, find the page to be replaced
        if(!page_found)
        {
            page_faults++;

            int max_distance = -1;
            int replace_index = -1;

            // Find the page with the maximum distance to its next occurrence
            for(j = 0; j < num_frames; j++)
            {
                int distance = 0;
                for(k = i+1; k < num_pages; k++)
                {
                    if(frames[j] == pages[k])
                        break;
                    distance++;
                }

                if(distance > max_distance)
                {
                    max_distance = distance;
                    replace_index = j;
                }
            }

            // Replace the page at the index with the maximum distance
            frames[replace_index] = pages[i];
        }

        // Print the current state of frames
        printf("Page %d: ", pages[i]);
        for(j = 0; j < num_frames; j++)
        {
            if(frames[j] == -1)
                printf(" - ");
            else
                printf(" %d ", frames[j]);
        }
        printf("\n");
    }

    // Print the total number of page faults
    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}
