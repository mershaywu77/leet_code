// @algorithm @lc id=101 lang=cpp 
// @title symmetric-tree


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include <deque>
#include <stack>
using namespace std;
// @test([1,2,2,3,4,4,3])=true
// @test([1,2,2,null,3,null,3])=false
// @test([1,0])=false
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
    bool isSymmetric(TreeNode* root) {
        deque<int> q;
        stack<TreeNode*> stk;
        TreeNode* tmp = root;
        while((tmp != nullptr) || (!stk.empty())) {
            if (tmp != nullptr) {
                stk.push(tmp);
                tmp = tmp->left;
            } else {
                tmp = stk.top();
                stk.pop();
                q.push_back(tmp->val);
                tmp = tmp->right;
            }
        }
        while (!q.empty()) {
            if (q.size() == 1) {
                return true;
            }
            if (q.front()==q.back()) {
                q.pop_back();
                q.pop_front();
            } else {
                return false;
            }
        }
        return true;
    }
};