#include <vector>
#include <string>
using namespace std;

class Solution {
    void backTrace(vector<vector<string>> &out, vector<string>& temp, int x, int y, int n, int count){
        if(x >= temp.size() && count >= n){
            out.push_back(temp);
            return;
        }else if(x >= temp.size()){
            return;
        }

        if(check(temp, x, y, n) == true){
            temp[x][y] = 'Q';
            backTrace(out, temp, x + (y + 1) / n, (y + 1) % n, n, count+1);
            temp[x][y] = '.';


        }
        backTrace(out, temp, x + (y + 1) / n, (y + 1) % n, n, count);
    }

    bool check(vector<string>& temp, int x, int y, int n){
        for(int i = y - 1; i >= 0; i--){
            if(temp[x][i] == 'Q') return false;
        }

        for(int i = x - 1; i >= 0; i--){
            if(temp[i][y] == 'Q') return false;
        }

        for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--){
            if(temp[i][j] == 'Q') return false;
        }

        for(int i = x - 1, j = y + 1; i >=0 && j < n; i--, j++){
            if(temp[i][j] == 'Q') return false;
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n, '.'));
        vector<vector<string>> res;
        backTrace(res, temp, 0, 0, n, 0);
        return res;
    }
};