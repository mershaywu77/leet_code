# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        if root is None:
            return []
        
        flag = True # True means normal order, False means reverse order
        deque, value_list = [], []
        deque.append(root)
        
        while deque:
            size_of_same_level = len(deque)
            values_of_same_level = []
            
            while size_of_same_level:  # # here is a good idea since we only iterate nodes of a certain level in each outer loop
                node = deque.pop(0)

                values_of_same_level.append(node.val)
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)

                size_of_same_level -= 1
            
            if flag is True:
                value_list.append(values_of_same_level)
                flag = False
            else:
                value_list.append(values_of_same_level[::-1])  # here is the difference from question 102
                flag = True
        
        return value_list
