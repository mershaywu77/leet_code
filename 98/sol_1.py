# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        # we perform depth-first Search and inorder traversal to obtain a list of all node values of binary tree, then judge if this list is 
        # in ABSOLUTELY ascending order.
        
        # This method is quite cumbersome as it's both time and memory consuming because we need to collect all elements of binary tree...
        
        if not root:
            return False
        
        def InOrder(root, res):
            
            if not root:
                return
            
            InOrder(root.left, res)
            res.append(root.val)
            InOrder(root.right, res)
            
            return res
        
        inorder_values = []
        InOrder(root, inorder_values)
        
        for i in range(len(inorder_values)-1):
            if inorder_values[i] >= inorder_values[i+1]:  # should be ">=" instead of ">" cuz of ABSOLUTELY ascending order
                return False
        
        return True
