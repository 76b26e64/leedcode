/*
 * Problem: 373. Find K Pairs with Smallest Sums
 * Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 * Difficulty: Medium
 * Approach: priority queue
 * Complexity: Time: O(nlogn), Space: O(n) 
 * Edge cases: nums1 is empty, nums2 is empty, k less than equal 0 . 
*/


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        if (nums1.empty() || nums2.empty() || k <= 0) {
            return {};
        }

        int nums1_size = nums1.size();
        int nums2_size = nums2.size();

        vector<vector<int>> ret;
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> min_heap;
        
        min_heap.push({nums1[0] + nums2[0], {0, 0}});
        for(int i = 0; i < k; i++){
            if(min_heap.empty()){
                break;
            }

            auto top = min_heap.top();
            min_heap.pop();
            int nums1_index = top.second.first;
            int nums2_index = top.second.second;

            ret.push_back({nums1[nums1_index], nums2[nums2_index]});
            
            if(nums2_index < nums2_size - 1){
                min_heap.push({nums1[nums1_index] + nums2[nums2_index + 1], {nums1_index, nums2_index + 1}});
            }
            
            if(nums2_index == 0 && nums1_index < nums1_size - 1){
                min_heap.push({nums1[nums1_index + 1] + nums2[nums2_index], {nums1_index + 1, nums2_index}});
            }
        }

        return ret;
    }
};