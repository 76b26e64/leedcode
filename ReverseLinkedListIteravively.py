class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head

        node = head 
        return_head = None
        while node != None:
          
            answer = ListNode()
            answer.next = return_head 
            answer.val = node.val
            
            node = node.next
            return_head = answer

        return return_head 


