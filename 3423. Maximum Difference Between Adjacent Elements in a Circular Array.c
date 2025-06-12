/*
3423. Maximum Difference Between Adjacent Elements in a Circular Array
Solved
Easy
Topics
Hint
Given a circular array nums, find the maximum absolute difference between adjacent elements.

Note: In a circular array, the first and last elements are adjacent.

 

Example 1:

Input: nums = [1,2,4]

Output: 3

Explanation:

Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.

Example 2:

Input: nums = [-5,-10,-5]

Output: 5

Explanation:

The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.

 

Constraints:

2 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

#define MAX_VAL (101)
#define MIN_VAL (-101)

int calc_diff(int a, int b){
    int diff;

    if(b < a){
        diff = a - b;
    }else{
        diff = b - a;
    } 

    return diff;
}

int maxAdjacentDistance(int* nums, int numsSize) {
    if(!nums && numsSize <= 1){
        return 0;
    }

    int max_diff = MIN_VAL;
    int diff = 0;
    for(int i = 0; i < numsSize-1; i++){
        diff =  calc_diff(nums[i], nums[i+1]);
        if(max_diff < diff){
            max_diff = diff;
        }
    }
        
    diff = calc_diff(nums[0], nums[numsSize-1]);
    if(max_diff < diff){
        max_diff = diff;
    }

    return max_diff; 
}