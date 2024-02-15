#include <vector>
#include <iostream>
using namespace std;

/*
* 首次提交用例：[[6,9,7]]未通过
* 需要注意去重！
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = (min(matrix.size(), matrix.back().size()) + 1) / 2;
        vector<int> res;
        for (int i = 0; i < n; i++){
            int x = i;
            int y = i;

            // 上行
            for (; y < (int)matrix.back().size() - 1 - i; y++){
                if(matrix[x][y] != INT_MAX){
                    res.push_back(matrix[x][y]);
                    matrix[x][y] = INT_MAX;
                }

            }

            // 右竖
            for (; x < (int)matrix.size() - 1 - i; x++){
                if(matrix[x][y] != INT_MAX){
                    res.push_back(matrix[x][y]);
                    matrix[x][y] = INT_MAX;
                }
            }

            // 下行
            for (; y > i; y--){
                if(matrix[x][y] != INT_MAX){
                    res.push_back(matrix[x][y]);
                    matrix[x][y] = INT_MAX;
                }
            }

            // 左竖
            for(; x > i; x--){
                if(matrix[x][y] != INT_MAX){
                    res.push_back(matrix[x][y]);
                    matrix[x][y] = INT_MAX;
                }
            }
        }

        if(matrix.size() == matrix.back().size() && (matrix.size() % 2 == 1)){
            res.push_back(matrix[matrix.size() / 2][matrix.size() / 2]);
        }

        return res;
    }
};