// @algorithm @lc id=450 lang=cpp 
// @title delete-node-in-a-bst


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([5,3,6,2,4,null,7],3)=[5,4,6,2,null,null,7]
// @test([5,3,6,2,4,null,7],0)=[5,3,6,2,4,null,7]
// @test([],0)=[]
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (root->val == key) {
            return merge(root->left, root->right);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
    
    TreeNode* merge(TreeNode* ltree, TreeNode* rtree) {
        if (ltree == nullptr) {
            return rtree;
        }
        if (ltree->right == nullptr) {
            ltree->right = rtree;
        } else {
            ltree->right = merge(ltree->right, rtree);
        }
        return ltree;
    }
};