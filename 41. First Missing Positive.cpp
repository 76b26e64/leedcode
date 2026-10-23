/*
 * Problem: 41. First Missing Positive
 * Link: https://leetcode.com/problems/first-missing-positive/description/
 * Difficulty: hard
 * Approach: Cycle Sort
 * Complexity: Time: O(n), Space: O(1)
 * Edge cases: 
 *  - nums.size() == 0; 
 *  - nums.size() == 1 (positive num/negative num);
 *  - Include 0
 *  - Duplicated num;
 *  - All nums are negative;
 *  - Include num is more nums.size();
 *  - All nums are more nums.size();
 *  - All 1 <= num <= nums.size() are included; 
*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            while(0 < nums[i] && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                std::swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1){
                return i + 1;
            }
        }
        return n+1;
    }
};