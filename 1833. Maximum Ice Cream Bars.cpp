/*
 * Problem: 1833. Maximum Ice Cream Bars
 * Link: https://leetcode.com/problems/maximum-ice-cream-bars/description
 * Difficulty: Miduum
 * Approach: Counting sort
 * Complexity: Time O(n), Space O(n)
 * Edge cases: 
 *  costs.length <= 0, coins <= 0, costs[i] >= 100000, coins >= 100000000
 *  Sum of cost equal coins. 
 *  All cost are 1 or 100000.
 *  Cannot buy anything
*/


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max_cost = *max_element(costs.begin(), costs.end());
        vector<int> cost_nums(max_cost+1);
        for(auto cost : costs){
            cost_nums[cost]++;
        }

        int icecream = 0;
        for(int i = 0; i <= max_cost; i++){
            if(coins < i){
                break;
            }

            if(cost_nums[i] == 0){
                continue;
            }

            int purchase_count = min(cost_nums[i], coins/i);
            icecream += purchase_count;
            coins -= (purchase_count * i);
        }

        return icecream;
        
    }
};