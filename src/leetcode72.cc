#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // 插入
        for(int i = 1; i < dp.back().size(); i++) dp[0][i] = dp[0][i - 1] + 1;

        // 删除
        for(int i = 1; i < dp.size(); i++) dp[i][0] = dp[i - 1][0] + 1;

        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp.back().size(); j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1]);
                }else{
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1, dp[i - 1][j - 1] + 1);
                }
            }
        }

        return dp.back().back();
    }
};