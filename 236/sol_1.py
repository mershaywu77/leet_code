# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        # This question is the upgraded version of Q.235, the difference from Q.235 is 
        # the given tree is NOT necessarily a binary serach tree, we lose the useful condition 
        # where the searching node'val is in between p.val and q.val
        
        # We need to find the ancestors of p and q respectively, i.e. ancestor of p & ancestor of q
        # these ancestor of p and ancestor of q have a common father node, meaning ancestor of p and
        # ancestor of q are left node and righr node of this father node, and THIS COMMON FATHER
        # NODE IS THE LOWEST COMMON ANCESTOR NODE.
        
        
        # For this question, we perform the DFS traversal on the given binary tree, we will 
        # definitely find p node and q node in traversal. When we find p or q, just return its
        # father node. Otherwise, it would return None when traversal is in a wrong sub-tree
        
        if not root:
            return root
        
        if p==root or q==root:
            return root
        
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        
        if left and right:  # we find the lowest common ancestor node
            return root
        
        # AT THIS MONMENT, there is at most one of the left and right nodes is not None
        # if both left and right nodes are None, just return right one
        if left:
            return left
        else:
            return right
