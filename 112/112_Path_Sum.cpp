// @algorithm @lc id=112 lang=cpp 
// @title path-sum


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
using namespace std;
// @test([5,4,8,11,null,13,4,7,2,null,null,null,1],22)=true
// @test([1,2,3],5)=false
// @test([1,2], 1)=false
// @test([],0)=false
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<TreeNode*> stk;
        int actualSum = 0;
        TreeNode* tmp = root;
        while ((tmp!=nullptr) || (!stk.empty())) {
            if (tmp!=nullptr) {
                stk.push(tmp);
                actualSum += tmp->val;
                tmp = tmp->left;
            } else {
                if ((stk.top()->left == nullptr) &&
                     (stk.top()->right == nullptr)) {
                    if (actualSum == targetSum) {
                        return true;
                    }
                } 
                if (stk.top() -> right == nullptr) {
                    actualSum -= stk.top()->val;
                }
                tmp = stk.top() ->right;
                stk.pop();
            }
        }
        return actualSum == targetSum;
    }
};



        // if (!root) {
        //     return (targetSum == 0);
        // }
        // if (root->val > targetSum) {
        //     return false;
        // } else if (root->val == targetSum) {
        //     return true;
        // } else {
        //     int remain = targetSum - root->val;
        //     return (hasPathSum(root->left, remain) || hasPathSum(root->right, remain));
        // }