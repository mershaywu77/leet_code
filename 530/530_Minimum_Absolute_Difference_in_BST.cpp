// @algorithm @lc id=530 lang=cpp 
// @title minimum-absolute-difference-in-bst


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([4,2,6,1,3])=1
// @test([1,0,48,null,null,12,49])=1
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
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) {
            return INT_MAX;
        }
        int dist = -1;
        int last = INT_MIN;
        inOrder(root, dist, last);
        return dist;
    }

    void inOrder(TreeNode* root, int& dist, int& last) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left, dist, last);
        if (dist != -1) {
            int tmp = root->val - last;
            if (tmp < dist) {
                dist = tmp;
            }
        } else {
            dist = INT_MAX;
        }
        last = root->val;
        inOrder(root->right, dist, last);
    }
};