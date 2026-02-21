/*
 * Problem: 138. Copy List with Random Pointer
 * Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/
 * Difficulty: Medium
 * Approach: Search next nodes, and random node.
 * Complexity: Time :O(n^2) Space : O(n)
 * Edge cases: head == nullptr, n(length = 1)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }

        Node* new_head = new Node(head->val);
        Node* new_prev = nullptr;
        Node* curr = head->next;
        int n {1};
        while(curr != nullptr){
            Node* new_curr = new Node(curr->val);
            if(new_head->next == nullptr){
                new_head->next = new_curr;
            }else{
                new_prev->next = new_curr;
            }
            new_prev = new_curr;
            curr = curr->next;
            n++;
        }

        for(int i = 0; i < n; i++){
            curr = head;
            Node *new_curr = new_head;
            for(int j = 0; j < i; j++){
                curr = curr->next;
                new_curr = new_curr->next;
            }

            curr = curr->random;
            int m {0};
            while(curr != nullptr){
                curr = curr->next;
                m++;
            }
            
            Node* new_random = new_head;
            for(int j = 0; j < (n-m); j++){
                new_random = new_random->next;
            }
            
            new_curr->random = new_random;
        }

        return new_head;
    }
};    