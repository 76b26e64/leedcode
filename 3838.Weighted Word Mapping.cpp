/*
 * Problem: 3838. Weighted Word Mapping
 * Link: https://leetcode.com/problems/weighted-word-mapping/description/
 * Difficulty: Easy
 * Approach: 
 * Complexity: Time O(n); Space O(n) 
 * Edge cases: word empty; weights lenght is not 26;
*/

class Solution {
public:

    static constexpr int MOD = 26;

    int convert_word(const string& word, const vector<int>& weights) {
        int total = 0; 
        for(const auto& c : word){
            total += weights[c - 'a'];
        }
        return total % MOD;
    }

    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string answer = "";

        if(words.empty() || weights.size() != 26){
            return answer;
        }

        for(const auto& word : words){
            //convert word
            int weight = convert_word(word, weights);
            //calclate character
            char c = static_cast<char>(('z' - weight));
            //add to answer
            answer += c;
        }
       
        return answer;
    }
};