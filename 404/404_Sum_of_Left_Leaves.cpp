// @algorithm @lc id=404 lang=cpp 
// @title sum-of-left-leaves


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([3,9,20,null,null,15,7])=24
// @test([1])=0
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        if (root->left != nullptr &&
            root->left->right == nullptr &&
            root->left->left == nullptr) {
            // it is left leave;
            return root->left->val + sumOfLeftLeaves(root->right);
            }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};