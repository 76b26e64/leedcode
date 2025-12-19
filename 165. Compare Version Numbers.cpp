
/*
165. Compare Version Numbers
Solved
Medium
Topics
conpanies icon
Companies
Hint
Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 

Example 1:

Input: version1 = "1.2", version2 = "1.10"

Output: -1

Explanation:

version1's second revision is "2" and version2's second revision is "10": 2 < 10, so version1 < version2.

Example 2:

Input: version1 = "1.01", version2 = "1.001"

Output: 0

Explanation:

Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

Example 3:

Input: version1 = "1.0", version2 = "1.0.0.0"

Output: 0

Explanation:

version1 has less revisions, which means every missing revision are treated as "0".

 

Constraints:

1 <= version1.length, version2.length <= 500
version1 and version2 only contain digits and '.'.
version1 and version2 are valid version numbers.
All the given revisions in version1 and version2 can be stored in a 32-bit integer.

*/

class Solution {

private:
    void split(const std::string& s, std::vector<std::string>&tokens, const std::string& delimiter) {
        size_t start = 0;
        size_t end;

        while ((end = s.find(delimiter, start)) != std::string::npos) {
            tokens.push_back(s.substr(start, end - start));
            start = end + delimiter.length();
        }
        tokens.push_back(s.substr(start));
    }


public:
    int compareVersion(string version1, string version2) {
        string delimiter =  ".";
        std::vector<std::string> v1_digits;
        std::vector<std::string> v2_digits;
    
        split(version1, v1_digits, delimiter);
        split(version2, v2_digits, delimiter);
        
        std::size_t v1_size = v1_digits.size();
        std::size_t v2_size = v2_digits.size();
        std::size_t small_size;
        std::size_t large_size;
        std::vector<std::string> *remain;
        
        if(v1_size <= v2_size){
            small_size = v1_size;
            large_size = v2_size;
            remain = &v2_digits;
        }else{
            small_size = v2_size;
            large_size = v1_size;
            remain = &v1_digits;
        }

        for(int i = 0; i < small_size; i++){
            int v1_num = std::stoi(v1_digits.at(i));
            int v2_num = std::stoi(v2_digits.at(i));
            if(v1_num < v2_num){
                return -1;
            }else if(v2_num < v1_num){
                return 1;
            }
        }

        if(v1_size == v2_size){
            return 0;
        }
        
        for(int i = small_size; i < large_size; i++){
            int num = std::stoi(remain->at(i));
            if(num != 0){
                return (v1_size < v2_size) ? -1 : 1;
            }
        }

        return 0;
    }
}