// @algorithm @lc id=669 lang=cpp 
// @title trim-a-binary-search-tree


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,0,2],1,2)=[1,null,2]
// @test([3,0,4,null,2,null,null,1],1,3)=[3,2,null,1]
// @test([2,1,3],3,4)=[3]
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return root;
        }
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        root->left = trimBST(root->left, low, root->val);
        root->right = trimBST(root->right, root->val, high);
        return root;
    }
};