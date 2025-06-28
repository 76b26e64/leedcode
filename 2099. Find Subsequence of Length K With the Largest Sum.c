/*
2099. Find Subsequence of Length K With the Largest Sum
Solved
Easy
Topics
conpanies icon
Companies
Hint
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
 

Constraints:

1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int index;
    int value;
} val_t;

int sort_value(const void *a, const void *b){
    return ((val_t *)b)->value - ((val_t *)a)->value;
}

int sort_index(const void *a, const void *b){
    return ((val_t *)a)->index - ((val_t *)b)->index;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    if(!nums || numsSize <= 0 || k <= 0 || !returnSize){
        return NULL;
    }
    
    val_t *vals = calloc(numsSize, sizeof(val_t));
    for(int i = 0; i < numsSize; i++){
        vals[i].index = i;
        vals[i].value = nums[i];
    }

    qsort(vals, numsSize, sizeof(val_t), sort_value);
    qsort(vals, k, sizeof(val_t), sort_index);
    int *ret = calloc(k, sizeof(int));
    for(int i = 0; i < k; i++){
        ret[i] = vals[i].value;
    }

    free(vals);
    *returnSize = k;
    return ret; 
}