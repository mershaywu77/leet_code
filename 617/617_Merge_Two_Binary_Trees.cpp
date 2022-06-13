// @algorithm @lc id=617 lang=cpp 
// @title merge-two-binary-trees


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algm/algm.h"
using namespace std;
// @test([1,3,2,5],[2,1,3,null,4,null,7])=[3,4,5,5,4,null,7]
// @test([1],[1,2])=[2,2]
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        } else if (root1 != nullptr && root2 == nullptr) {
            return root1;
        } else if (root1 == nullptr && root2 != nullptr) {
            return root2;
        } else {
            int s = root1->val + root2->val;
            return new TreeNode(s, mergeTrees(root1->left,root2->left),
                                 mergeTrees(root1->right, root2->right));
        }
        // queue<TreeNode*> q1;
        // queue<TreeNode*> q2;
        // q1.push(root1);
        // q2.push(root2);
        // if (root1 == nullptr && root2 == nullptr) {
        //     return nullptr;
        // } 
        // while (!q1.empty() || !q2.empty()) {
        //     int l1 = q1.size();
        //     int l2 = q2.size();
        //     int lm = max(l1, l2) 
        //     for (int i=0; ++i){            }
        // }
    }
};