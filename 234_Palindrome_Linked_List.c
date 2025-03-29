/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {

    if(!head){
        return false;
    }else if(head->next == NULL){
        //Node num is 1
        return true;
    }else if(head->next->next == NULL){
        //Node num is 2
        if(head->next->val == head->val){
            return true;
        }else{
            return false;
        }
    }

    //find middle node
    struct ListNode* first = head;
    struct ListNode* second = head;
    bool is_odd = true;
    while(first){
        if(first->next == NULL){
            //odd
            break;
        }else if(first->next->next == NULL){
            //even
            is_odd = false;
            break;
        }
        first = first->next->next;
        second = second->next;
    }
    first = second->next;
    
    //Reverse half of node
    struct ListNode* prev = NULL;
    struct ListNode* cur  = head;
    while(cur != NULL && cur != first){
        struct ListNode* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }

    if(is_odd){
        second = second->next;
    }

    while(first && second){
        //printf("fisrt=%d second=%d\n",first->val, second->val);

        if(first->val != second->val){
            return false;
        }
        first = first->next;
        second = second->next;
    }

    // Checked all node, so first and second should be NULL;
    if(first || second){
        return false;
    }

    return true;
}
