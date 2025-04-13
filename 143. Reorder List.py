# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class DoubleListNode
     def __init__(self, val=0, next=None, prev=None):
         self.val = val
         self.next = next
         self.prev = prev

class Solution:
    
    def reorderList(self, head: Optional[ListNode]) -> None:

        if head:
            return 
        
        array = []
        single = head
        while single:
            array.append(single)
            single = single.next

        i = 0
        j = len(array) - 1

        if i == j:
            return

        i = 1
        while True:
            head.next = array[j]
            j -= 1
            if i >= j:
                return

            head = head.next
            head.next = array[i]
            i += 1
            if i >= j:
                return
            
            head = head.next


            



    '''
    def makeDoubleList(self, single: Optional[ListNode], double: Optional[ListNode]) -> None:
        prev = None

        while single.next:
            double.val = single.val
            double.next = single.val
            double.prev = prev
            
            pvev = single
            single = single.next
            double = double.next

    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        single = head
        double = New DoubleListNode()

        makeDoubleList(single, double)

        double_head = double
        double_tail = double

        while double_tail.next:
            double_tail = double_tail.next

        while True:
            head = double_head
    '''
            

