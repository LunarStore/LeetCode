#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int num = 1;
        for(int cnt = 0; cnt < n / 2; cnt++){
            int x = cnt;
            int y = cnt;

            for(; y < n - 1 - cnt; y++){
                res[x][y] = num++;
            }

            for(; x < n - 1 - cnt; x++){
                res[x][y] = num++;
            }

            for(; y > cnt; y--){
                res[x][y] = num++;
            }

            for(; x > cnt; x--){
                res[x][y] = num++;
            }
        }

        if((n % 2) == 1){
            res[n / 2][n / 2] = num++;
        }

        return res;
    }
};