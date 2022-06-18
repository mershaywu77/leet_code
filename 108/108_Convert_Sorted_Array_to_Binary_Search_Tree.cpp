// @algorithm @lc id=108 lang=cpp 
// @title convert-sorted-array-to-binary-search-tree


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([-10,-3,0,5,9])=[0,-3,9,-10,null,5]
// @test([1,3])=[3,1]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = nums.size();
        if (l == 0) {
            return nullptr;
        }
        int mid = l / 2;
        TreeNode* root = new TreeNode(nums.at(mid));
        vector<int> nums_l(nums.begin(), nums.begin()+mid);
        vector<int> nums_r(nums.begin()+mid+1, nums.end());
        root->left = sortedArrayToBST(nums_l);
        root->right = sortedArrayToBST(nums_r);
        return root;
    }
};