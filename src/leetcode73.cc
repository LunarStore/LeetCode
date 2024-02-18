#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rows(matrix.size(), true);
        vector<bool> cols(matrix.back().size(), true);

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.back().size(); j++){
                if(matrix[i][j] == 0){
                    rows[i] = false;
                    cols[j] = false;
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.back().size(); j++){
                if(rows[i] == false || cols[j] == false){
                    matrix[i][j] = 0;
                }
            }
        }

        return;
    }
};