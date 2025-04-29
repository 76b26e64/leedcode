/*
405. Convert a Number to Hexadecimal
Solved
Easy
Topics
Companies
Given a 32-bit integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.

All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.

Note: You are not allowed to use any built-in library method to directly solve this problem.

 

Example 1:

Input: num = 26
Output: "1a"
Example 2:

Input: num = -1
Output: "ffffffff"
 

Constraints:

-231 <= num <= 231 - 1*/

#define BASE (16)
#define RET_LEN (9)

char* toHex(int num) {
    if(num == 0){
        return "0";
    }

    char *ret = calloc(RET_LEN, sizeof(char));
    int index = RET_LEN-1;
    ret[index--] = '\0';

    unsigned int x = (unsigned int)num;
    while(x != 0){
        char val = x & 0xF;
        if(val < 10){
            ret[index--] = '0' + val;
        }else{
            ret[index--] = 'a' + val - 10;
        }
        x >>= 4;
    }

    return &ret[index+1];
}