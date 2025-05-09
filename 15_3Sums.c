/*
15. 3Sum
Solved
Medium
Topics
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <malloc.h>

int sortfunc(const void *a, const void *b){
    return *((int *)a) - *((int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    if(!nums  || numsSize <=2 || !returnSize || !returnColumnSizes){
        return NULL;
    }

    //int **ret = malloc(0);
    int **ret = malloc((numsSize * (numsSize-1)) * sizeof(int*));
    *returnSize = 0;
    //*returnColumnSizes = malloc(0);
    *returnColumnSizes = malloc((numsSize * (numsSize-1)) * sizeof(int*));

    qsort(nums, numsSize, sizeof(int), sortfunc);
    for(int i = 0; i < numsSize; i++){
        if(i != 0 && nums[i] == nums[i-1]){
            continue;
        }

        int low = i+1;
        int high = numsSize-1;
        while(low<high){
            if((nums[i] + nums[low] + nums[high]) == 0){
                int *tmp = malloc(3 * sizeof(int));
                tmp[0] = nums[i];
                tmp[1] = nums[low];
                tmp[2] = nums[high];

                //ret = realloc(ret, (*returnSize+1) * sizeof(int*));
                ret[*returnSize] = tmp;

#if 0 
                struct mallinfo2 mi;
                mi = mallinfo2();
                printf("Total amount of memory : %zu bytes\n", mi.arena);
                printf("Total free blocks      : %zu bytes\n", mi.ordblks);
                printf("Total allocated space  : %zu bytes\n", mi.uordblks);
                printf("Total free space       : %zu bytes\n", mi.fordblks);
#endif 
                //*returnColumnSizes = realloc(*returnColumnSizes, (*returnSize+1) * sizeof(int*));
                (*returnColumnSizes)[*returnSize] = 3;
                
                *returnSize = (*returnSize) + 1;
                low++;
                high--;
                while(low < high && nums[low-1] == nums[low]){
                    low++;
                }
            }else if((nums[i] + nums[low] + nums[high]) < 0){
                low++;
            }else{
                high--;
            }
        }

    }

    return ret;
}