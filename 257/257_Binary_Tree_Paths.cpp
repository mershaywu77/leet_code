// @algorithm @lc id=257 lang=cpp 
// @title binary-tree-paths


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algm/algm.h"
using namespace std;
// @test([1,2,3,null,5])=["1->2->5","1->3"]
// @test([1])=["1"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<string> ans;
        if (root==NULL){
            return ans;
        }
        while (!q.empty()) {
            int l = q.size();
            string s;
            for (int i=0; i<l; ++i) {
                s.append(to_string(q.front()->val));
                if ((q.front()->left == nullptr) && 
                    (q.front()->right == nullptr)) {
                        ans.push_back(s);
                    }
                    
            }
        }
    }
};