#include <string>
#include <vector>
using namespace std;

//无脑dp
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.length() + 1, vector<bool>(s.length()  + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= p.length(); i++) dp[i][0] = p[i - 1] == '*' && dp[i - 1][0];
        for(int i = 1; i <= p.length(); i++){
            for(int j = 1; j <= s.length(); j++){
                if(isalpha(p[i - 1])){
                    dp[i][j] = s[j - 1] == p[i - 1] && dp[i - 1][j - 1];
                }else if(p[i - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{  //for *
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - 1] || dp[i][j - 1];
                }
            }
        }

        return dp.back().back();
    }
};