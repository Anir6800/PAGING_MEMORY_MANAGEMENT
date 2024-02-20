#include <stdio.h>

int main() {
    int page_size, num_pages, num_frames, logical_address, page_no, offset;

    printf("Enter the page size (in bytes): ");
    scanf("%d", &page_size);

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    if (num_pages > num_frames) {
        printf("Error: Number of pages cannot exceed number of frames.\n");
        return 1;
    }

    int page_table[num_pages];
    for (int i = 0; i < num_pages; i++) {
        page_table[i] = -1;
    }

    while (1) {
        printf("\nEnter the logical address (or -1 to exit): ");
        scanf("%d", &logical_address);

        if (logical_address == -1) {
            break;
        }

        if (logical_address < 0 || logical_address >= page_size * num_pages) {
            printf("Error: Invalid logical address.\n");
            continue;
        }

        page_no = logical_address / page_size;
        offset = logical_address % page_size;

        int frame_no = page_table[page_no];
        if (frame_no != -1) {
            printf("Logical address %d is already in frame %d, offset %d.\n", logical_address, frame_no, offset);
            continue;
        }

        printf("Page fault! Simulating page replacement...\n");
   
        int victim_frame = 0; 
        page_table[page_no] = victim_frame;

        printf("Accessing data from secondary storage for page %d...\n", page_no);

        printf("Accessed data at logical address %d (physical address: frame %d, offset %d).\n",
               logical_address, victim_frame, offset);
    }

    return 0;
}
