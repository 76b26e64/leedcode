/*
 * Problem: 3612. Process String with Special Operations I
 * Link: https://leetcode.com/problems/process-string-with-special-operations-i/description/
 * Difficulty: Medium
 * Approach: 
 * Complexity: Time O(n^2), Space O(m)
 * Edge cases: 
*/


class Solution {
public:
    string processStr(string s) {
        string answer;
        for(auto c : s){
            switch(c){
                case '#':
                    answer += answer;
                    break;
                case '%':
                    if (!answer.empty()) {
                        std::reverse(answer.begin(), answer.end());
                    }
                    break;
                case '*':
                    if (!answer.empty()) {
                       answer.pop_back();
                    }
                    break;
                default:
                    answer += c;
                    break;
            }
        }
        return answer;
    }
};