#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
    void backTrace(int n, int k,  int curNum, int pos, vector<int> &temp, vector<vector<int>> &out){
        if(pos >= k){
            out.push_back(temp);

            return;
        }

        for(int i = curNum; i <= n; i++){
            temp.push_back(i);
            backTrace(n, k, i + 1, pos + 1, temp, out);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;

        backTrace(n, k, 1, 0, temp, res);
        return res;
    }
};