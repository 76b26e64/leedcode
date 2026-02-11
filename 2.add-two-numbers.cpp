/*
 * Problem: 2.Add Two Numbers
 * Link: https://leetcode.com/problems/add-two-numbers/description/
 * Difficulty: Medium
 * Approach: Walk through two list at once.
 * Complexity: Time O(n), Space O(n)
 * Edge cases: l1 and/or l2 nullptr, carry last time
*/
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry {0};
        ListNode* head = nullptr;
        ListNode* node = nullptr;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int sum = num1 + num2 + carry;
            int val = sum % 10;
            carry = sum / 10;
            if(head == nullptr){
                head = new ListNode(val);
                node = head; 
            }else{
                node->next = new ListNode(val);
                node = node->next;
            }
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return head;
        
    }
};

