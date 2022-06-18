// @algorithm @lc id=222 lang=cpp 
// @title count-complete-tree-nodes


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
using namespace std;
// @test([1,2,3,4,5,6])=6
// @test([])=0
// @test([1])=1
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
    int countNodes(TreeNode* root) {
        int cnt = 0;
        stack<TreeNode*> stk;
        TreeNode* tmp = root;
        while ((tmp != nullptr) || !stk.empty()) {
            if (tmp != nullptr) {
                stk.push(tmp);
                tmp = tmp->left;
            } else {
                ++cnt;
                tmp = stk.top()->right;
                stk.pop();
            }
        }
        return cnt;
    }
};