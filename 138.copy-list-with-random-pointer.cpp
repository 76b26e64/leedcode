/*
 * Problem: 138. Copy List with Random Pointer
 * Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/
 * Difficulty: Medium
 * Approach: Hashmap
 * Complexity: Time :O(n) Space : O(n)
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
    
        std::unordered_map<Node*, Node*> u = 
        {
            {head, new_head}
        };

        Node* new_curr = nullptr;
        while(curr != nullptr){
            new_curr = new Node(curr->val);
            if(new_head->next == nullptr){
                new_head->next = new_curr;
            }else{
                new_prev->next = new_curr;
            }
            u[curr] = new_curr;
            new_prev = new_curr;
            curr = curr->next;
            n++;
        }
       
        curr = head;
        new_curr = new_head;        

        while(curr != nullptr){
            new_curr->random = u[curr->random];
            curr = curr->next;
            new_curr = new_curr->next;
        }

        return new_head;
    }
};    