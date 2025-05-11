/*
Given an integer num, return a string of its base 7 representation.


Example 1:

Input: num = 100
Output: "202"
Example 2:

Input: num = -7
Output: "-10"
 
Constraints:
-107 <= num <= 107
 */

#define BASE (7)
#define ANSWER_SIZE (20)

char* convertToBase7(int num) {
    if(num == 0){
        return "0";
    }

    bool minus = false;
    if(num < 0){
        minus = true;
        num *= -1;
    }

    char *ans = calloc(ANSWER_SIZE, sizeof(char));
    int index = ANSWER_SIZE - 2; // last index is '\0'
    while(num > 0){
        ans[index--] = '0' + (char)(num % BASE);
        num /= BASE;
    };

    if(minus){
        ans[index--] = '-';
    }

    return &ans[index+1];
}