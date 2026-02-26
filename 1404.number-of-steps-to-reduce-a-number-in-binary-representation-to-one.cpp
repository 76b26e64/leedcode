/*
 * Problem:1404. Number of Steps to Reduce a Number in Binary Representation to One 
 * Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/
 * Difficulty: midium
 * Approach: Simulation
 * Complexity: Time : O(n) Space : O(1)
 * Edge cases: s == ""; s = "1"; s == "0"; s == "11"; s == "10"
*/

using namespace std;
class Solution {
public:
    int numSteps(string s) {
        if(s == ""){
            return 0;
        }

        int count {0};
        int idx = s.size() - 1;
        bool carry {false};
        while(idx >= 0){
            if(s.at(idx) == '0'){
                //devide 2 is 1 bit shift right ;
                idx--;
            }else{
                if(idx == 0 && !carry){
                    break;
                }

                //add 1
                s.at(idx) = '0';

                // check carry
                int i;
                for(i = idx-1; i >=0; i--){
                    if(s.at(i) == '0'){
                        s.at(i) = '1';
                        break;
                    }else{
                        s.at(i) = '0';
                    }
                }
                if(i < 0){
                    carry = true;
                }
            }
            count++;
        }

        return count;
    }
};
