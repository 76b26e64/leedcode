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

        std::stack<char> st;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }else if(c == ')' || c == '}' || c == ']'){
                if(st.empty()){
                    return false;
                }

                switch(c){
                    case ')':
                        if(st.top() != '('){
                            return false;
                        }
                        st.pop();
                        break;
                    case '}':
                        if(st.top() != '{'){
                            return false;
                        }
                        st.pop();
                        break;
                    case ']':
                        if(st.top() != '['){
                            return false;
                        }
                        st.pop();
                        break;
                    default:
                        // Not reached
                        return false;
                }
            }else{
                //invalid character
                return false;
            }
        }

        if(!st.empty()){
            return false;
        }

        return true;
    }
};
// @lc code=end

