// @algorithm @lc id=783 lang=cpp 
// @title search-in-a-binary-search-tree


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([4,2,7,1,3],2)=[2,1,3]
// @test([4,2,7,1,3],5)=[]
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return nullptr;
        } else {
            if (root->val == val) {
                return root;
            } else {
                TreeNode* tmp = searchBST(root->left, val);
                if (tmp != nullptr) {
                    return tmp;
                } else {
                    return searchBST(root->right, val);
                }
            }
        }
    }
};