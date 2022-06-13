// @algorithm @lc id=501 lang=cpp 
// @title find-mode-in-binary-search-tree


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
using namespace std;
// @test([1,null,2,2])=[2]
// @test([0])=[0]
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
// Do an in-order traversal:
// If the pointed value changes,
// write to the vector<int> if its count >= previous count.
// if ==, push_back
// if >, clear the vector and add
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> md;
        if (root==nullptr) {
            return md;
        }
        int cnt = 0;
        int max_cnt = 0;
        TreeNode* tmp = root;
        while ((tmp != nullptr) || (!stk.empty())) {
            if (tmp != nullptr) {
                stk.push(tmp);
                tmp = tmp->left;
            } else {
                if (md.empty()) {
                    md.push_back(stk.top()->val);
                    ++cnt;
                } else if (stk.top()->val == md.back()) {
                    ++cnt;
                } else {
                    process(cnt, max_cnt, md);  
                    md.push_back(stk.top()->val); 
                    max_cnt = max(max_cnt, cnt);
                    cnt = 1;
                }
                tmp = stk.top()->right;
                stk.pop();
            }
        }
        process(cnt, max_cnt, md);
        return md;
    }

    void process(int cnt, int max_cnt, vector<int>& md) {
        if (cnt > max_cnt) {
            int last = md.back();
            md.clear();
            md.push_back(last);
        } else if (cnt < max_cnt) {
            md.pop_back();
        }
    }
};