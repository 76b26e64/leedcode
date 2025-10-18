/*
13. Roman to Integer
Solved
Easy
Topics
Companies
Hint
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/

class Solution {

private:
    const map<char, int> vals = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    static bool roman_rule_check(char prev, char curr){
        return (prev == 'I' && (curr == 'V' || curr == 'X')) ||
               (prev == 'X' && (curr == 'L' || curr == 'C')) ||
               (prev == 'C' && (curr == 'D' || curr == 'M'));
    }

public:
    int romanToInt(string s) {
        int answer = 0;
        char prev_c = 0;
        int prev = 0;
        for(char c : s){
            auto it = vals.find(c);
            if(it == vals.end()){
                return 0;
            }
            int curr = it->second;
            if(prev >= curr){
                answer += curr;
            }else{
                if(prev_c && !roman_rule_check(prev_c, c)){
                    return 0;
                }
                answer += curr - (prev * 2);
            }
            prev = curr;
            prev_c = c;
        }
        return answer;
    }
};