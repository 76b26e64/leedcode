# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoList(self, base: Optional[ListNode], sub: Optional[ListNode]) -> Optional[ListNode]:

        if base.next == None:
            base.next = sub
            return base

        if sub == None:
            return base

        if base.val <= sub.val <= base.next.val:
            next_base = base.next
            next_sub = sub.next
            base.next = sub
            base.next.next = next_base
            return self.mergeTwoList(base.next, next_sub)
        else:
            return self.mergeTwoList(base.next, sub)
            
    
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None:
            return list2
        
        if list2 == None:
            return list1

        if list1.val <= list2.val:
            self.mergeTwoList(list1, list2)
            return list1
        else:
            self.mergeTwoList(list2, list1)        
            return list2        