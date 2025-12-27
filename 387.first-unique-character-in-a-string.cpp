/*
 * Problem:387. First Unique Character in a String
 * Link: https://leetcode.com/problems/first-unique-character-in-a-string/description/
 * Difficulty: Easy
 * Approach: Two-pass counting
 * Complexity: Time O(n), Space O(1)
 * Edge cases: n=0, 2^31-1 
*/

using std::string;
using std::array;
class Solution {

private:
    static constexpr int LETTER_NUM = 26;

public:
    int firstUniqChar(string s) {
        array<int, LETTER_NUM> counter{}; // zero-initialized

        for(char c : s){
            counter[c - 'a']++;
        } 
        
        for(int i = 0; i < s.size(); i++){
            if(counter[s[i] - 'a'] == 1){
                return i;
            }
        }
        
        return -1;
    }
};

