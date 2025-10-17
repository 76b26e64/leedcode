/*
12. Integer to Roman
Solved
Medium
Topics
conpanies icon
Companies
Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.

 

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV
 

Constraints:

1 <= num <= 3999
*/

#include <stdlib.h>
#include <string.h>

#define GIVEN_NUM_MIN (1)
#define GIVEN_NUM_MAX (3999)
#define ANSWER_LEN_MAX (16)
#define SIZE_OF_ARRAY(x) (sizeof(x)/sizeof(x[0]))

char* intToRoman(int num) {
    if(num < GIVEN_NUM_MIN || GIVEN_NUM_MAX < num){
        return NULL;
    }

    char *answer = calloc(ANSWER_LEN_MAX, sizeof(char));
    if(!answer){
        return NULL;
    }

    const int  values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const char *symbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    size_t offset = 0;
    for(int i = 0; i < SIZE_OF_ARRAY(values); i++){
        while(num >= values[i]){
            size_t symbol_len = strlen(symbols[i]);
            if(ANSWER_LEN_MAX <= symbol_len + offset){
                return NULL;
            }
            memcpy(&answer[offset], symbols[i], symbol_len);
            offset += symbol_len;
            answer[offset] = '\0';
            num -= values[i];
        }
    }

    return answer;
}