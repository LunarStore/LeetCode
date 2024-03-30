#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* cur = root;
        while(!stk.empty() || cur != nullptr) {
            while(cur != nullptr){
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();

            res.push_back(cur->val);
            cur = cur->right;
        }

        return res;
    }
};