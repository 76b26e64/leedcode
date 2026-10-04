/*
 * Problem: 1046. Last Stone Weight
 * Link: https://leetcode.com/problems/last-stone-weight/description/
 * Difficulty: Easy
 * Approach: Priority Queue
 * Complexity: Time: O(nlogn), Space:O(n)
 * Edge cases: stones size = 0 or 1.
*/

#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        if(stones.empty()){
            return 0;
        }else if(stones.size() == 1){
            return stones[0];
        }

        std::priority_queue<int> stones_queue(stones.begin(), stones.end());
        while(stones_queue.size() > 1){
            int heaviest = stones_queue.top();
            stones_queue.pop();
            int second_heaviest = stones_queue.top();
            stones_queue.pop();
            if(heaviest != second_heaviest){
                stones_queue.push(heaviest - second_heaviest);
            }
        }

        return stones_queue.empty() ? 0 : stones_queue.top();

    }
};