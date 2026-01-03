/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

/*
 * Problem: 20. Valid Parentheses 
 * Link: https://leetcode.com/problems/valid-parentheses/description/ 
 * Difficulty: Easy
 * Approach: Stacks
 * Complexity: Time O(n) Space O(n)
 * Edge cases: 
*/

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        static const std::unordered_map<char, char> pairs = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };
 
        std::stack<char> st;
        for(char c : s){
            if(pairs.contains(c)){
                st.push(c);
            }else if(!st.empty() && pairs.find(st.top())->second == c){
                st.pop();
            }else{
                return false;
            }
        }

        return st.empty();
    }
};
// @lc code=end

