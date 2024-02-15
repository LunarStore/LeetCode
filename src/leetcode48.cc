#include <vector>

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix[0].size(); i++){
            int begin = 0, end = matrix.size() - 1;
            while(begin < end){
                swap(matrix[begin][i], matrix[end][i]);
                begin++;
                end--;
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = i + 1; j < matrix[0].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        return;
    }
};