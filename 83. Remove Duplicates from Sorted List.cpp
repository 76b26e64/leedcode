/*
 * Problem: 83. Remove Duplicates from Sorted List
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Difficulty: Easy
 * Approach: Straight-Forward Approach
 * Complexity: Time: O(n), Space: O(1)
 * Edge cases: head is null, only one list
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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head == nullptr){
            return head;
        }

        ListNode* current = head;
        int last_val = head->val;

        ListNode* prev = current;
        current = current->next;
        while(current != nullptr){
            if(last_val != current->val){
                last_val = current->val;
                prev = current;
            }else{
                prev->next = current->next;
            }
            current = current->next;
        }

        return head;
    }
};