void sortColors(int* nums, int numsSize) {

    for(int i=0; i < numsSize; i++){
        int min_index = i;
        int current_index = i;
        for(int j = current_index+1; j<numsSize; j++){
            if (nums[j] < nums[min_index]){
                min_index = j;
            }
        }
        int tmp = nums[current_index];
        nums[current_index] = nums[min_index];
        nums[min_index] = tmp;
    }
}