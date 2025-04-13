void sortColors(int* nums, int numsSize) {

    int counts[3] = {0};
    for(int i=0; i<numsSize; i++){
        counts[nums[i]]++;
    }

    int starting_index = 0;
    for(int i=0; i<3; i++){
        int count = counts[i];
        counts[i] = starting_index;
        starting_index += count;
    }

    int sorted_nums[numsSize];
    memset(sorted_nums, 0, sizeof(sorted_nums));
    for(int i=0; i<numsSize; i++){
        sorted_nums[counts[nums[i]]] = nums[i];
        counts[nums[i]]++;
    }
    memcpy(nums, sorted_nums, sizeof(sorted_nums));
}
