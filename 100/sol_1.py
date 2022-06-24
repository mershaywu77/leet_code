# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        
        # The naive idea is we perform the modified preorder traversal for two given binary tree,
        # collecting the node values into list respectively, finally compare the two collected list
        # if they are equal
        
        # The modification is we also add None to the result list because two trees with same
        # traversal result may have different structures
        
        def PreOrder_Traversal_Breadth_First(root):
            
            stack, res_list = [root], []
            while stack:
                node = stack.pop()
                if node:
                    res_list.append(node.val)
                    stack.append(node.right)
                    stack.append(node.left)
                else:
                    res_list.append(None)
            
            return res_list
        
        p_tree = PreOrder_Traversal_Breadth_First(p)
        q_tree = PreOrder_Traversal_Breadth_First(q)
        
        return p_tree==q_tree
