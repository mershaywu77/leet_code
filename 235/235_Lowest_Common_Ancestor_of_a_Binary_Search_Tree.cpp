// @algorithm @lc id=235 lang=cpp 
// @title lowest-common-ancestor-of-a-binary-search-tree


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([6,2,8,0,4,7,9,null,null,3,5],2,8)=6
// @test([6,2,8,0,4,7,9,null,null,3,5],2,4)=2
// @test([2,1],2,1)=2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// use preorder traversal
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left , p, q);
        
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};