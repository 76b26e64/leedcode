# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def doSwap(self, parent, current, count):
        if current == None:
            return

        if (count % 2) == 1:
            tmp = parent.val
            parent.val = current.val
            current.val = tmp

        count += 1
        self.doSwap(current, current.next, count)
        return
    
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head        

        self.doSwap(head, head.next, 1)
        return head