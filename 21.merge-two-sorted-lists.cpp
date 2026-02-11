/*
 * Problem: 21. Merge Two Sorted Lists
 * Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
 * Difficulty: Easy
 * Approach: Iteration for two lists at once
 * Complexity: Time O(n), Space
 * Edge cases: list1 and/or list2 are nullptr, length 0. 
*/

class Solution {
static bool compare(std::optional<int> val1, std::optional<int> val2){
    if(val1 == std::nullopt && val2 == std::nullopt){
        return false;
    }else if(val1 != std::nullopt && val2 == std::nullopt){
        return true;
    }else if(val1 == std::nullopt && val2 != std::nullopt){
        return false;
    }
    return (val1 <= val2);
}
    
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode *head = nullptr;
        ListNode *node = nullptr;
        while(list1 || list2){
            std::optional<int> val1 = std::nullopt;
            if(list1){
                val1 = list1->val; 
            }
            std::optional<int> val2 = std::nullopt;
            if(list2){
                val2 = list2->val; 
            }

            if(head == nullptr){
                if(compare(val1, val2)){
                    head = list1;
                    list1 = list1->next;
                }else{
                    head = list2;
                    list2 = list2->next;
                }
                node = head;
            }else{
                if(compare(val1, val2)){
                    node->next = list1;
                    list1 = list1->next;
                }else{
                    node->next = list2;
                    list2 = list2->next;
                }
                node = node->next;
            }
        }

        return head;
   }
};
