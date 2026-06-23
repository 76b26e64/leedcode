/*
 * Problem: 1189. Maximum Number of Balloons
 * Link: https://leetcode.com/problems/maximum-number-of-balloons/description/
 * Difficulty: easy
 * Approach: Counting Characters
 * Complexity: Time : O(n), Space : O(1)
 * Edge cases: 
 *  text = "", does not include 'balloon', text equals "balloon"
 *  
*/

class Solution {
private: 
    int maxNumberOfWord(const std::string &text, const std::string &word) {
        if(word.empty() || text.length() < word.length()){
            return 0;
        }

        std::unordered_map<char, int> required;
        for(const char c : word){
            required[c]++;
        }
        
        std::unordered_map<char, int> counts;
        for(const char c : text){
            if(required.contains(c)){
                counts[c]++;
            }
        }
       
        int min_value = text.length() + 1;
        for(const auto& [key, value] : required){
            min_value = std::min(min_value, counts[key] / value);
        }

        return min_value;
    }

public:
    int maxNumberOfBalloons(string text) {
        return maxNumberOfWord(text, "balloon");
    }
};

