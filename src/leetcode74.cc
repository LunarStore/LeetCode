#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int begin = 0, end = matrix.size() * matrix.back().size() - 1;

        while(begin <= end){
            int mid = (begin + end) / 2;
            int midX = mid / matrix.back().size();
            int midY = mid % matrix.back().size();
            if(matrix[midX][midY] < target){
                begin = mid + 1;
            }else if(matrix[midX][midY] > target){
                end = mid - 1;
            }else{
                return true;
            }
        }

        return false;
    }
};