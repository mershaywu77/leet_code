# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        
        if not nums:
            return None
        
        mid_index = len(nums)//2
        node = TreeNode(nums[mid_index])
        
        node.left =  self.sortedArrayToBST(nums[:mid_index])
        node.right = self.sortedArrayToBST(nums[mid_index+1:])  # there is a need to take much care of here, it's easy to write "mid_index" instead of "mid_index+1"
        
        return node
