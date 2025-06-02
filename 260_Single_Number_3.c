/*
260. Single Number III
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
 

Constraints:

2 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each integer in nums will appear twice, only two integers will appear once.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {

    // Define answers as x, y

    // Get XOR of x and y
    unsigned int bitmask = 0;
    for(int i = 0; i < numsSize; i++){
        bitmask ^= nums[i];
    }

    // Get 1 bit of x 
    unsigned int diff = bitmask & (-bitmask);

    // Get x for getting XOR from include 1 bit(diff)
    // execpt x, all numbers exist twice, so I can get x.
    unsigned int x = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] & diff){
            x ^= nums[i];
        }
    }

    *returnSize = 2;
    int *answer = calloc(*returnSize, sizeof(int));
    answer[0] = (int)x;
    // y get from x XOR (x XOR y)
    answer[1] = (int)(bitmask ^ x);

    return answer;

}
