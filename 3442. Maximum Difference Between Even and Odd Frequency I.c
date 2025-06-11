/*
3442. Maximum Difference Between Even and Odd Frequency I
Solved
Easy
Topics
conpanies icon
Companies
Hint
You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference.

 

Example 1:

Input: s = "aaaaabbc"

Output: 3

Explanation:

The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
The maximum difference is 5 - 2 = 3.
Example 2:

Input: s = "abcabcab"

Output: 1

Explanation:

The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
The maximum difference is 3 - 2 = 1.
 

Constraints:

3 <= s.length <= 100
s consists only of lowercase English letters.
s contains at least one character with an odd frequency and one with an even frequency.
*/

#define CHAR_NUM (26)
int maxDifference(char* s) {
    if(!s){
        return 0;
    }

    int count[CHAR_NUM] = {0,};
    int s_len = strlen(s);
    for(int i = 0; i < s_len; i++){
        count[s[i] - 'a']++;
    }

    int max_freq_odd  = 0;
    int min_freq_even = s_len;
    for(int i = 0; i < CHAR_NUM; i++){
        int freq = count[i];
        if(freq % 2){
            if(max_freq_odd < freq){
                max_freq_odd = freq;
            }
        }else{
            if(freq != 0 && freq < min_freq_even){
                min_freq_even = freq;
            }
        }
    }

    return max_freq_odd - min_freq_even;
}