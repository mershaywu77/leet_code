// @algorithm @lc id=775 lang=cpp 
// @title n-ary-tree-preorder-traversal


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "algm/algm.h"
using namespace std;
// @test([1,null,3,2,4,null,5,6])=[1,3,5,6,2,4]
// @test([1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14])=[1,2,3,6,7,11,14,4,8,12,5,9,13,10]

// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };


class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> stk;
        Node* tmp = root;
        vector<int> v;
        while ((tmp != nullptr) || (!stk.empty())) {
            if (tmp != nullptr) {
                v.push_back(tmp->val);
                for (auto it=tmp->children.rbegin(); it != tmp->children.rend(); ++it) {
                    stk.push(*it);
                }

            }
            tmp = stk.top();
            stk.pop();
        }
        return v;
    }
};