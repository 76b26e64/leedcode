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

    bool minus = false;
    if(num < 0){
        minus = true;
        num *= -1;
    }

    int tmp[100] = {0};
    int digit = 0;
    int val = 0;
    while(num > 0){
        val = num % BASE;
        tmp[digit++] = val;
        num /= BASE;
    }

    if(digit == 0){
        return "0";
    }

    char *ret;
    int index;
    if(minus){
        ret = calloc(digit+2, sizeof(char));
        ret[index++] = '-';
    }else{
        ret = calloc(digit+1, sizeof(char));
    }

    while(digit > 0){
        ret[index++] = '0' + (char)tmp[--digit];
    }

    return ret;
    
}