// @algorithm @lc id=110 lang=cpp 
// @title balanced-binary-tree


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([3,9,20,null,null,15,7])=true
// @test([1,2,2,3,3,null,null,4,4])=false
// @test([1,2,2,3,null,null,3,4,null,null,4])=false
// @test([])=true
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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        } 
        if (abs(height(root->left) - height(root->right)) <= 1) {
            return isBalanced(root->left) && isBalanced(root->right); 
        }
        return false; 
    }

    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(1+height(root->left), 1+height(root->right));
    }
};