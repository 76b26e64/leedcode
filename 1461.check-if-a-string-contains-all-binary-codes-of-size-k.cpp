/*
 * Problem: 1461. Check If a String Contains All Binary Codes of Size K
 * Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/
 * Difficulty: Medium
 * Approach: Hashmap (unorderd_map)
 * Complexity: Time: O(n) Space : O(n)
 * Edge cases: S is empty, k is 0 or negative number
*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s == ""){
            return false;
        }
        if(k <= 0){
            return false;
        }

        int length = s.length();
        std::string_view view = s;
        std::unordered_map<std::string_view, int> hash;
        for(int i = 0; i < length - (k-1); i++){
            hash[view.substr(i, k)] = 1;
        }

        if(hash.size() != (1 << k)){
            return false;
        }

        return true;
    }
};



