// @algorithm @lc id=98 lang=cpp 
// @title validate-binary-search-tree


#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([2,1,3])=true
// @test([5,1,4,null,null,3,6])=false
// @test([0,-1]) = true
// @test([5,4,6,null,null,3,7]) = false
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
        if (root == nullptr) {
            return false;
        } else {
            if (root->left == nullptr &&
                root->right == nullptr) {
                    return true;
            } 
            else if (root->left != nullptr &&
                     root->right != nullptr) {
                return  isValidBST(root->right) &&
                        isValidBST(root->left) &&
                        (MaxBST(root->left) < root->val) &&
                        (MinBST(root->right) > root->val);
            } 
            else {
                if (root->left != nullptr) {
                    return isValidBST(root->left) &&
                          (MaxBST(root->left) < root->val);
                } else {
                    return isValidBST(root->right) && 
                          (MinBST(root->right) > root->val);
                }
            }
        }
    }
    int MaxBST(TreeNode* root) {
        if (root == nullptr) {
            return INT_MIN;
        } 
        int ml = MaxBST(root->left);
        int mr = MaxBST(root->right);
        if (ml >= mr) {
            if (root->val <= ml) {
                return ml;
            }
        } else {
            if (root->val <= mr) {
                return mr;
            }
        }
        return root->val;
    }
    int MinBST(TreeNode* root) {
        if (root == nullptr) {
            return INT_MAX;
        } 
        int ml = MinBST(root->left);
        int mr = MinBST(root->right);
        if (ml >= mr) {
            if (root->val >= mr) {
                return mr;
            }
        } else {
            if (root->val >= ml) {
                return ml;
            }
        }
        return root->val;
    }
};