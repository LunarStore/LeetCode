#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backTrace(vector<string>& out, string& temp, int left, int right, int n){
        if(left == n && right == n){
            out.push_back(temp);
            return;
        }
        if(left < right){   //非法
            return;
        }
        if(left < n){
            temp.push_back('(');
            backTrace(out, temp, left + 1, right, n);
            temp.pop_back();
        }

        if(right < n){
            temp.push_back(')');
            backTrace(out, temp, left, right + 1, n);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;
        backTrace(res, temp, 0, 0, n);
        return res;
    }
};