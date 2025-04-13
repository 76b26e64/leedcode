"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:

        answer = []
        if not root:
            return answer

        def searchtree(node):
            while node.children:
                child = node.children.pop(0)
                searchtree(child)
            answer.append(node.val)
            return

        searchtree(root)
        return answer
