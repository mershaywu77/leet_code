// @algorithm @lc id=538 lang=cpp 
// @title convert-bst-to-greater-tree


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([4,1,6,0,2,5,7,null,null,null,3,null,null,null,8])=[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
// @test([0,null,1])=[1,null,1]
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
// Do an inverted in-order traversal;
public:
    TreeNode* convertBST(TreeNode* root) {
        int s = 0;
        invertInorderSum(root, s);
        return root;
    }

    void invertInorderSum(TreeNode* root, int& s) {
        if (root == nullptr) {
            return;
        }
        invertInorderSum(root->right, s);
        s = root->val + s;
        root->val = s;
        invertInorderSum(root->left, s);
    }
};