/*
2131. Longest Palindrome by Concatenating Two Letter Words
Solved
Medium
Topics
Companies
Hint
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

 

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".
 

Constraints:

1 <= words.length <= 105
words[i].length == 2
words[i] consists of lowercase English letters.

*/

#define ALPHABET_NUM (26)


static int words_count[ALPHABET_NUM][ALPHABET_NUM];

int longestPalindrome(char** words, int wordsSize) {

    if(!words || wordsSize <= 0){
        return 0;
    }

    bzero(words_count, sizeof(words_count));
    for(int i = 0; i < wordsSize; i++){
        words_count[words[i][0] - 'a'][words[i][1] - 'a']++;
    }

    int central = 0;
    int answer  = 0;
    for(int i = 0; i < ALPHABET_NUM; i++){
        for(int j = i; j < ALPHABET_NUM; j++){
            if(i == j){
                if(words_count[j][j] % 2 == 0){
                    answer += (words_count[j][j] * 2);
                }else{
                    answer += (words_count[j][j] - 1) * 2;
                    if(central == 0){
                        central = 2;
                    }
                }
            }else{
                if(words_count[i][j] < words_count[j][i]){
                    answer += (words_count[i][j] * 4);
                }else{
                    answer += (words_count[j][i] * 4);
                }
            }
        }
    }

    answer += central;
    return answer;
}