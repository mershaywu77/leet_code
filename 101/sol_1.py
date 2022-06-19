# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        
        # This question is similar to Q.100, we also perform DFS on left sub-tree and right sub-tree
        # SIMULTANEOUSLY
        
        def dfs(left_node, right_node):
            if left_node is None and right_node is None:
                return True
            elif left_node is None or right_node is None:
                return False
            elif left_node.val != right_node.val:
                return False
            else:
                return dfs(left_node.left, right_node.right) and dfs(left_node.right, right_node.left)
            
        return dfs(root.left, root.right)
