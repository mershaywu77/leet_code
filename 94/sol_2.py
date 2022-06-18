# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        
        # Bread-first iteratoin
        
        stack = [root]  # push root to the stack
        res = []  # save traversal result
        
        while stack:
            node = stack.pop()
            
            if node:
                stack.append(node.right)
                stack.append(node)
                stack.append(node.left)
            else:  
                # when the node is None node of leaf node
                # Becase the number of None nodes = Number of nodes in sub-tree + 1,
                # once we have None node, and when pop it out, it means we can pop sam enumber 
                # of nodes out of stack
                
                if stack:  
                
                # Because the total number of None nodes in a binary tree = total number of nodes in
                # binary tree, it means when we pop the last None node out of stack, there is no
                # more available normal node to pop out IN THE STACK, so we need to add a if
                # condition to prevent executing the following steps in the final loop
                
                    prev_node = stack.pop()
                    res.append(prev_node.val)
        
        return res
