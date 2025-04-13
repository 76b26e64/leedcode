# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def reverseNode(self, node, rev):
        if node == None:
            return rev
        
        rev_head = ListNode()
        rev_head.next = rev
        rev_head.val = node.val
        return self.reverseNode(node.next, rev_head)

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.reverseNode(head, None)
