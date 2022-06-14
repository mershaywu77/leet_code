# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        
        # Given preorder:[root, left, right] ; inorder:[left, root, right], we construct the binary tree and return the root node
        
        # we got root node value from preorder[0], since there is a condition that preorder and inorder consist of unique values, 
        # we also got the index of root node from inorder by searching value of root node
        
        # Then we know the left sub-tree and right sub-tree of root node from inorder, as well as how many of them (amount)
        
        # To construct the binary tree, recursion could be performed
        
        if len(preorder) == 0:
            return None
        
        root_node_value = preorder[0]
        root_node = TreeNode(root_node_value)
        root_node_index_in_inorder = amount_of_nodes_in_left_sub_tree = inorder.index(root_node_value)
        
        root_node.left = self.buildTree(preorder[1:amount_of_nodes_in_left_sub_tree+1], inorder[:amount_of_nodes_in_left_sub_tree])
        root_node.right = self.buildTree(preorder[1+root_node_index_in_inorder:], inorder[1+root_node_index_in_inorder:])
        
        return root_node
