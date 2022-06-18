// @algorithm @lc id=513 lang=cpp 
// @title find-bottom-left-tree-value


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algm/algm.h"
using namespace std;
// @test([2,1,3])=1
// @test([1,2,3,4,null,5,6,null,null,7])=7
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lnum = 0;
        if (root==nullptr) {
            return lnum;
        }
        while (!q.empty()) {
            int l = q.size();
            lnum = q.front()->val; 
            for (int i=0; i<l; ++i) {
                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        return lnum;
    }
};