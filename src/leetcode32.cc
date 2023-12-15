#include <string>
#include <vector>
using namespace std;

//超时，需要降维
class Solution {
public:
    int longestValidParentheses(string s) {
        //二维dp
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        if(s.empty() == true) return 0;
        int res = 0;
        for(int i = s.length() - 1; i >= 0; i--){

            for(int j = i + 1; j < s.length(); j++){
                if(s[i] == '(' && s[j] == ')'){
                    dp[i][j] = dp[i + 1][j - 1] || j - i == 1;
                }

                for(int k = i + 1; k + 1 < j && dp[i][j] == false; k++){
                    dp[i][j] = dp[i][k] && dp[k + 1][j];
                }

                if(dp[i][j] == true) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};