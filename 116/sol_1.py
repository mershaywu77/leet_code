"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        
        # Perform the binary tree level order traversal, saving the nodes of the same level in a 
        # list for each outer loop, then set *next pointer for each node in the list
        
        if not root:
            return None
        
        deque = [root]
        
        while deque:
            current_length_of_deque = len(deque)
            current_level_nodes_list = deque.copy()
            
            while(current_length_of_deque):
                node = deque.pop(0)
                if node.left is not None and node.right is not None:
                    deque.append(node.left)
                    deque.append(node.right)
                
                current_length_of_deque -= 1
            
            i = 0
            while i<len(current_level_nodes_list)-1 :
                current_level_nodes_list[i].next = current_level_nodes_list[i+1]
                i += 1
            
            current_level_nodes_list[i].next = None
            
        return root
