#include <stdio.h>
#include <stdlib.h>

int main() {
    
    float nums[4][2] = {
        {0,0},
        {0,0},
        {0,0},
        {0,0}
    };

    printf("size %lu", sizeof(nums));

    int size = sizeof(nums);
    printf("\nint size:%d", size);

    float **ptr = nums;

    printf("\n\nsize %lu", sizeof(ptr));

    size = sizeof(ptr);
    printf("\nint size:%d", size);

    return 0;
}
