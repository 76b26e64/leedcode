/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minCosts(int* cost, int costSize, int* returnSize) {

    int *ret = malloc(costSize * sizeof(int));
     int min_cost = 101;
    for(int i=0; i<costSize; i++){
         if(min_cost > cost[i]){
             min_cost = cost[i];
         }
         ret[i] = min_cost;
    }

    *returnSize = costSize;
    return ret;
 }