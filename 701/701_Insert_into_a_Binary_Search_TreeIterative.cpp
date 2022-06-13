// @algorithm @lc id=784 lang=cpp 
// @title insert-into-a-binary-search-tree


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
using namespace std;
// @test([4,2,7,1,3],5)=[4,2,7,1,3,5]
// @test([40,20,60,10,30,50,70],25)=[40,20,60,10,30,50,70,null,null,25]
// @test([4,2,7,1,3,null,null,null,null,null,null],5)=[4,2,7,1,3,5]
// @test([61,46,66,43,null,null,null,39,null,null,null],88)=[61,46,66,43,null,null,88,39]
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        stack<TreeNode*> stk;
        TreeNode* tmp = root;
        TreeNode* pnt_tmp = root;
        while (tmp != nullptr || !stk.empty()) {
            if (tmp != nullptr) {
                stk.push(tmp);
                pnt_tmp = tmp;
                tmp = tmp->left;
            } else {
                if (val < stk.top()->val) {
                    if (val > pnt_tmp->val) {
                        pnt_tmp->right = new TreeNode(val);
                    } else {
                        pnt_tmp->left = new TreeNode(val);
                    }
                    return root;
                }
                pnt_tmp = stk.top();
                tmp = stk.top()->right;
                stk.pop();
            }
        }
        pnt_tmp->right = new TreeNode(val);
        return root;
    }
};



