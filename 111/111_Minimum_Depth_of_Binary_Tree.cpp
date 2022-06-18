// @algorithm @lc id=111 lang=cpp 
// @title minimum-depth-of-binary-tree


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algm/algm.h"
using namespace std;
// @test([3,9,20,null,null,15,7])=2
// @test([2,null,3,null,4,null,5,null,6])=5
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if (root == NULL) {
            return 0;
        }
        vector<int> mD;
        int d = 1;
        while((q.empty()) {
            int l = q.size();
            for (int i=0; i<l; ++i) {
                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                } else {
                    mD.push_back();
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                } else {
                    return mD;
                }
                ++mD;
                q.pop();
            }
        }
        return mD;
    }
};