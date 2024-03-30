#include <vector>
#include <algorithm>
#include <string>
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
    vector<TreeNode*> dfs(int begin, int end){
        vector<TreeNode*> res;
        if(begin >= end){
            return { nullptr };
        }
        for(int i = begin; i < end; i++){
            vector<TreeNode*> lefts = dfs(begin, i);
            vector<TreeNode*> rights = dfs(i + 1, end);
            for(int j = 0; j < lefts.size(); j++){
                for(int k = 0; k < rights.size(); k++){
                    res.push_back(new TreeNode(i, lefts[j], rights[k]));
                }
            }
        }

        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n + 1);
    }
};