#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length(), 0);
        dp[0] = s[0] != '0' ? 1 : 0;

        for(int i = 1; i < s.length(); i++) {
            if(s[i] != '0') {
                dp[i] += dp[i - 1];
            }

            if(s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6'){
                dp[i] += i - 2 < 0 ? 1 : dp[i - 2];
            }
        }

        return dp.back();
    }
};