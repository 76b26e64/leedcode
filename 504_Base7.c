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

char* convertToBase7(int num) {
    if(num == 0){
        return "0";
    }

    bool minus = false;
    if(num < 0){
        minus = true;
        num *= -1;
    }

    int tmp = num;
    int digits = 1; //'\0'
    while(tmp > 0){
        digits++;
        tmp /= BASE;
    }

    if(minus){
        digits++;
    }

    char *ans = calloc(digits, sizeof(char));
    int index = digits - 2; // last index is '\0'
    while(num > 0){
        ans[index--] = '0' + (char)(num % BASE);
        num /= BASE;
    };

    if(minus){
        ans[0] = '-';
    }

    return ans;
}