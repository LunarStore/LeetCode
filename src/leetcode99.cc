#include <vector>
#include <algorithm>
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;

        TreeNode* cur = root;
        TreeNode* last = nullptr, *error1 = nullptr, *error2 = nullptr;
        while(!stk.empty() || cur != nullptr){
            while(cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if(last != nullptr && cur->val <= last->val && error1 == nullptr) {
                error1 = last;
            }
            if(cur->val <= last->val) {
                error2 = cur;
            }
            last = cur;
            cur = cur->right;
        }
        swap(error1->val, error2->val);
        return;
    }
};