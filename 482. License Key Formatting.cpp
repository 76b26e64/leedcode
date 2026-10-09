/*
 * Problem: 
 * Link: 
 * Difficulty: 
 * Approach: 
 * Complexity: 
 * Edge cases: 
*/


class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int s_len = s.length();

        if(k <= 0){
            return "";
        }
        if(k >= s_len){
            return s;
        }
        
        int alphanumeric_len = 0;
        for(int i = 0; i < s_len; i++){
            if(s.at(i) != '-'){
                alphanumeric_len++; 
            }
        }
        if(alphanumeric_len == 0){
            return "";
        }

        int ret_len = alphanumeric_len + (alphanumeric_len / k);
        if(alphanumeric_len % k == 0){
            ret_len--;
        }
        string ret(ret_len, '*');
       
        int pos = ret_len - 1;
        int count = 0;
        for(int i = s_len-1; i >= 0; i--){
            if(s.at(i) != '-'){
                if(std::islower(s.at(i)) != 0){
                    ret.at(pos--) = std::toupper(s.at(i));
                }else{
                    ret.at(pos--) = s.at(i);
                }

                count++;
                if(count % k == 0 && pos > 0){
                    ret.at(pos--) = '-';
                }
            }
        }
        return ret;
    }
};