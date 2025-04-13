#include <stdlib.h>

struct nums_s {
    int index;
    int num;
} typedef nums_t;

int compare(const void *a, const void *b) {
    return (((nums_t*)a)->num - ((nums_t*)b)->num);
}

int maxWidthRamp(int* nums, int numsSize) {

    nums_t *nums_array = malloc(sizeof(nums_t) * numsSize);
    if(nums_array == NULL) {
        return -1;
    }

    for(int i = 0; i < numsSize; i++){
        nums_array[i].index = i;
        nums_array[i].num = nums[i];
    }
    qsort(nums_array, numsSize, sizeof(nums_t), compare);

    int min_index = numsSize;
    int max_width = 0;
    for(int i = 0; i < numsSize; i++){
        if(max_width < nums_array[i].index - min_index){
            max_width = nums_array[i].index - min_index;
        }
        if(nums_array[i].index < min_index){
            min_index = nums_array[i].index;
        }
    }

    free(nums_array);

    return max_width;
}

/**
int maxWidthRamp(int* nums, int numsSize) {
    int max_width = 0;
    for(int i = 0; i < numsSize-1; i++){
        for(int j = i+1; j < numsSize; j++){
            if(nums[i] <= nums[j]){
                if(max_width < (j-i)){
                    max_width = j-i;
                }
            }
        }
    }
    return max_width;
}
**/
