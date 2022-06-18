#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void split(string param, char seg, vector<string> &arr)
{
    string temp = "";
    for (auto it = param.begin(); it != param.end(); it++)
    {
        if (*it == seg)
        {
            arr.push_back(temp);
            temp = "";
        }
        else
        {
            temp += *it;
        }
    }
    arr.push_back(temp);
};

TreeNode *serialTreeConstruct(string param) 
{
    int len = param.length();
    if (len <= 2)
    {
        return nullptr;
    }
    vector<string> nodeData;
    split(param.substr(1, len - 2), ',', nodeData);
    if (nodeData.size() == 0)
    {
        return nullptr;
    }

    int i = 0;
    int val = stoi(nodeData[i++]);
    TreeNode *root = new TreeNode(val);
    queue<TreeNode *> q;
    q.push(root);
    while (q.size() > 0)
    {
        TreeNode *node = q.front();
        q.pop();
        if (i == nodeData.size())
        {
            return root;
        }

        string leftVal = nodeData[i++];
        if (leftVal != "null")
        {

            node->left = new TreeNode(stoi(leftVal));
            q.push(node->left);
        }
        if (i == nodeData.size())
        {
            return root;
        }
        string rightVal = nodeData[i++];
        if (rightVal != "null")
        {

            node->right = new TreeNode(stoi(rightVal));
            q.push(node->right);
        }
    }
    return root;
};

void preOrderIterativeTravelsal(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> v;
    TreeNode* tmp = root;
    while ((tmp != nullptr) || (!stk.empty())) {
        if (tmp != nullptr) {
            stk.push(tmp);
            cout << tmp-> val << " ";;
            tmp = tmp->left;
        } else {
            tmp = stk.top(); 
            stk.pop();
            tmp = tmp->right;
        }
    } 
    cout << endl;
    return;
};

void inOrderIterativeTravelsal(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* tmp = root;
    while ((tmp != nullptr) || (!stk.empty())) {
        if (tmp != nullptr) {
            stk.push(tmp);
            tmp = tmp->left;
        } else {
            tmp = stk.top();
            cout << tmp-> val << " ";; 
            stk.pop();
            tmp = tmp->right;
        }
    }
    cout << endl;
    return;
};

void postOrderIterativeTravelsalDoubleStack(TreeNode* root) {
    stack<TreeNode*> stk;
    stack<TreeNode*> stk_rt;
    TreeNode* tmp = root;
    while ((tmp != nullptr) || (!stk.empty())) {
        if (tmp != nullptr) {
            stk.push(tmp);
            if (tmp->right != nullptr) {
                stk_rt.push(tmp->right);
            }
            tmp = tmp->left;
        } else {
            if ((!stk_rt.empty()) && (stk.top()->right == stk_rt.top())) {
                tmp = stk_rt.top();
                stk_rt.pop();
            } else {
                cout << stk.top()->val << " ";
                stk.pop();
            }
        }
    }
    cout << endl;
    return;
};

void postOrderIterativeTravelsalSingleStack(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* tmp = root;
    while ((tmp != nullptr) || (!stk.empty())) {
        if (tmp != nullptr) {
            stk.push(tmp);
            tmp = tmp->left;
        } else {
            tmp = stk.top()->right;
            if (tmp == nullptr) {
                while ((!stk.empty()) && (stk.top()->right == tmp)) {
                    cout << stk.top()->val << " ";
                    tmp = stk.top();
                    stk.pop();
                } 
                tmp = nullptr;
            } 
        }
    }
    cout << endl;
    return;
};


int main() {
    string c1 = "[1,2,3,4,5,6,7]";
    TreeNode* root1 = serialTreeConstruct(c1);

    preOrderIterativeTravelsal(root1);
    inOrderIterativeTravelsal(root1);
    postOrderIterativeTravelsalDoubleStack(root1);
    cout << "Single Stack: " << endl;
    postOrderIterativeTravelsalSingleStack(root1);


    string c2 = "[1,null,2,3]";
    TreeNode* root2 = serialTreeConstruct(c2);
    preOrderIterativeTravelsal(root2);
    inOrderIterativeTravelsal(root2);
    postOrderIterativeTravelsalDoubleStack(root2);
    cout << "Single Stack: " << endl;
    postOrderIterativeTravelsalSingleStack(root2);
    return 1;
}