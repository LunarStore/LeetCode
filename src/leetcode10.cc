#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        //动态规划
        vector<vector<bool>> dp(p.length() + 1, vector<bool>(s.length() + 1, false));
        dp[0][0] = true;

        for(int i = 1; i <= p.length(); i++) {
            dp[i][0] = p[i - 1] == '*' && dp[i - 2][0] == true;
        }
        for(int i = 1; i <= p.length(); i++){
            for(int j = 1; j <= s.length(); j++){
                if(isalpha(p[i - 1])){
                    dp[i][j] = p[i - 1] == s[j - 1] && dp[i - 1][j - 1] == true;
                }else if(p[i - 1] == '.'){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(p[i - 1] == '*'){
                    if(isalpha(p[i - 2])){
                        //用或者不用
                        dp[i][j] = dp[i - 2][j] == true || s[j - 1] == p[i - 2] && dp[i][j - 1] == true;
                    }else if(p[i - 2] == '.'){
                        dp[i][j] = dp[i - 2][j] == true || dp[i][j - 1] == true;
                    }
                }
            }
        }

        return dp[p.length()][s.length()];
    }
};