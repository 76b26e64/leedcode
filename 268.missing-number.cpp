 /*
 * Problem: 268. Missing Number
 * Link: https://leetcode.com/problems/missing-number/description/
 * Difficulty: Easy
 * Approach: Substructs all num from sum(0..n)
 * Complexity: Time O(n), Space O(1)
 * Edge cases: n=0, n=1, missing 0 or n, large input size 
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        long long answer = (long long)n * (n+1) / 2;  // sum from 0 to n;
        for(int num : nums){
            answer -= num;
        }
        return (int)answer;
    }
};

