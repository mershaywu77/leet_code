// @algorithm @lc id=98 lang=cpp 
// @title validate-binary-search-tree


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
using namespace std;
// @test([2,1,3])=true
// @test([5,1,4,null,null,3,6])=false
// @test([0,-1]) = true
// @test([5,4,6,null,null,3,7]) = false
// @test([-2147483648]) = true
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
    bool isValidBST(TreeNode* root) {
        int n = INT_MIN;
        stack<TreeNode*> stk;
        if (root == nullptr) {
            return false;
        }
        int cnt = 0;
        TreeNode* tmp = root;
        while ((tmp != nullptr) || !stk.empty()) {
            if (tmp != nullptr) {
                stk.push(tmp);
                tmp = tmp->left;
            } else {
                //dosomething;
                if (cnt == 0) {
                    n = stk.top() -> val;
                } else {
                    if (stk.top()->val <= n) {
                        return false;
                    } else {
                        n = stk.top()->val;
                    }
                }
                ++cnt;
                tmp = stk.top()->right;
                stk.pop();
            }
        }
        return true;
    }
};