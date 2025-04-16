int maxSubArray(int* nums, int numsSize) {
    if(!nums || numsSize <= 0){
        return 0;
    }
    
    int current_sum = 0;
    int max_sum = INT_MIN;
    for(int i = 0; i < numsSize; i++){
        current_sum += nums[i];
        if(max_sum < current_sum){
            max_sum = current_sum;
        }
        if(current_sum < 0){
            current_sum = 0;
        }
    }

    return max_sum;
}