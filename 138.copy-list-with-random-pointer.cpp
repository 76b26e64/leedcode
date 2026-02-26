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
        if(!head){
            return nullptr;
        }

        Node* new_head = new Node(head->val);
        std::unordered_map<Node*, Node*> u = 
        {
            {head, new_head}
        };

        Node* curr = head->next;
        Node* new_prev = new_head;
        for(curr = head->next; curr; curr = curr->next){
            new_prev->next = new Node(curr->val); //new_prev->next is new_curr
            u[curr]  = new_prev->next;
            new_prev = new_prev->next;
        }
       
        curr = head;
        Node *new_curr = nullptr;        
        for(curr = head, new_curr = new_head; 
            curr && new_curr; 
            curr = curr->next, new_curr = new_curr->next){
            new_curr->random = u[curr->random];
        }

        return new_head;
    }
};    