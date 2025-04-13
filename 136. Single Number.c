//136. Single Number
int singleNumber(int* nums, int numsSize) {

    if (nums == NULL || numsSize == 0){
        return 0;
    }

    int answer = 0;
    for(int i=0; i<numsSize; i++){
        answer ^= nums[i];
    }
    return answer;
}
