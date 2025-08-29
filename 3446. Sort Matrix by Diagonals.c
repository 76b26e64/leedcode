/*
3446. Sort Matrix by Diagonals
Solved
Medium
Topics
conpanies icon
Companies
Hint
You are given an n x n square matrix of integers grid. Return the matrix such that:

The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
The diagonals in the top-right triangle are sorted in non-decreasing order.
 

Example 1:

Input: grid = [[1,7,3],[9,8,2],[4,5,6]]

Output: [[8,2,3],[9,6,7],[4,5,1]]

Explanation:



The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:

[1, 8, 6] becomes [8, 6, 1].
[9, 5] and [4] remain unchanged.
The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:

[7, 2] becomes [2, 7].
[3] remains unchanged.
Example 2:

Input: grid = [[0,1],[1,2]]

Output: [[2,1],[1,0]]

Explanation:



The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to [2, 0]. The other diagonals are already in the correct order.

Example 3:

Input: grid = [[1]]

Output: [[1]]

Explanation:

Diagonals with exactly one element are already in order, so no changes are needed.

 

Constraints:

grid.length == grid[i].length == n
1 <= n <= 10
-105 <= grid[i][j] <= 105
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int increase(const void *a, const void *b){
    return *((int *)a) - *((int *)b);
}

int decrease(const void *a, const void *b){
    return *((int *)b) - *((int *)a);
}

int** sortMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {

    if(!grid || gridSize <= 0 || !gridColSize || *gridColSize <= 0 || !returnSize || !returnColumnSizes) {
        return NULL;
    }

    int row_size = gridSize;
    int col_size = gridSize;

    int **answer = calloc(row_size, sizeof(int *));
    *returnSize = row_size;
    *returnColumnSizes = calloc(row_size, sizeof(int));

    for(int i = 0; i < row_size; i++){
        answer[i] = calloc(col_size, sizeof(int)); 
        (*returnColumnSizes)[i] = col_size;
    }

    int vals[row_size];
    bzero(vals, sizeof(vals));
    for(int i = 0; i < row_size; i++){
        int val_number = row_size - i;

        for(int j = 0; j < val_number; j++){
            vals[j] = grid[i+j][j];
        }
        qsort(vals, val_number, sizeof(int), decrease);
        
        for(int j = 0; j < val_number; j++){
            answer[i+j][j] = vals[j];
        }
    }
    
    for(int i = 1; i < col_size; i++){
        int val_number = col_size - i;
        for(int j = 0; j < val_number; j++){
            vals[j] = grid[j][i+j];
        }
        qsort(vals, val_number, sizeof(int), increase);
        
        for(int j = 0; j < val_number; j++){
            answer[j][i+j] = vals[j];
        }
    }

    return answer;
    
}