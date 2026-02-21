/*
 * Problem: 25. Reverse Nodes in k-Group
 * Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 * Difficulty: hard
 * Approach: Iterative, check next k-Group
 * Complexity: Time : O(n) Space : O(1)
 * Edge cases: head == Nullptr, k == 1, Node num % k == 0
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1){
            return head;
        }

        ListNode* ret {head};
        ListNode* next_head {nullptr};
        ListNode* curr_head {nullptr};
        ListNode* prev {nullptr};
        ListNode* curr {nullptr};

        curr_head = curr = head;
        while(curr != nullptr){
            int i = 0;
            for(i = 0; i < k; i++){
                if(curr == nullptr){
                    return ret;
                }
                curr = curr->next;
            }
            next_head = curr;
            
            for(; i < 2*k-1; i++){
                if(curr == nullptr){
                    break;
                }
                curr = curr->next;
            }
            if(curr == nullptr){
                prev = next_head;
            }else{
                prev = curr;
            }
        
            curr = curr_head;
            for(int i = 0; i < k; i++){
                ListNode* tmp {nullptr};
                tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            if(ret == head){
                ret = prev;
            }
            curr_head = curr = next_head;
        }

        return ret;
    }
};
