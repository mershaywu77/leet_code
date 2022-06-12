# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        if root is None:
            return []
        
        deque = []
        deque.append(root)
        value_list = []  # to be returned
        
        while deque:
            size_of_same_level = len(deque)
            values_of_same_level = []
            
            while size_of_same_level:  # 妙在这里
                node = deque.pop(0)
                
                values_of_same_level.append(node.val)
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)
                
                size_of_same_level -= 1
                
            value_list.append(values_of_same_level)
            
        return value_list
