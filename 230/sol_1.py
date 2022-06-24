# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        
        # Given a binary search tree, the inorder traversal ([left, root, right])
        # of the binary search tree can give you the list of values in ascending order
        
        # And we just need the k th element in this list
        
        # Here the breadth-first (iterative) inorder traversal is applied
        
        def InOrder_Traversal_and_Find_K_th_smallest(root, k):
            
            stack, res = [root], []
            
            while stack:
                node = stack.pop()
                
                if node:
                    stack.append(node.right)
                    stack.append(node)
                    stack.append(node.left)
                
                else:
                    if stack:
                        prev_node = stack.pop()
                        res.append(prev_node.val)
                        
                        if len(res) == k:
                            return res[-1]
            
        value = InOrder_Traversal_and_Find_K_th_smallest(root, k)
        
        return value
