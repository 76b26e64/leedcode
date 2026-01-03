/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        const std::string remove_chars = "!?',;.";
        for (char& c : paragraph) {
            if(remove_chars.find(c) != std::string::npos){
                c = ' ';
            }
        }
        //std::cout << paragraph << std::endl;

        std::unordered_map<std::string, int> freq;
        std::istringstream iss(paragraph);
        std::string word;
        while (iss >> word) {   // splits by whitespace
            std::transform(word.begin(), word.end(), word.begin(),
                    [](unsigned char c) {
                        return std::tolower(c);
                    });
            if(std::ranges::find(banned, word) == banned.end()){
                //std::cout << word << std::endl;
                ++freq[word];
            }
        }

        if(freq.empty()){
            return "";
        }
        std::string most_common = std::max_element(freq.begin(), freq.end(), 
            [](auto& a, auto& b){return a.second < b.second; })->first;
        return most_common;
    }
};
// @lc code=end

