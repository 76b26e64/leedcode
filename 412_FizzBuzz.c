/*
Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
 

Example 1:

Input: n = 3
Output: ["1","2","Fizz"]
Example 2:

Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
Example 3:

Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 

Constraints:

1 <= n <= 104
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_STR_LEN (9)  // "FizzBuss¥0"
char** fizzBuzz(int n, int* returnSize) {
    if(n <= 0){
        return NULL;
    }

    char **ret = calloc(n, sizeof(char *));
    for(int i=1; i<=n; i++){
        char *buf = calloc(1, MAX_STR_LEN);
        if(i % 3 == 0 && i % 5 == 0){
            strncpy(buf, "FizzBuzz", 8); 
        }
        else if(i % 3 == 0){
            strncpy(buf, "Fizz", 4); 
        }
        else if(i % 5 == 0){
            strncpy(buf, "Buzz", 4); 
        }
        else{
            snprintf(buf, 8, "%d", i);
        }
        ret[i-1] = buf;
    }
    *returnSize = n;
    return ret; 
}