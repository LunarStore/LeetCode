#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    //暴力
    string longestPalindrome(string s) {
        string res;
        int pMid = 0;
        auto extendFind = [&s, &res](int l, int r)->pair<int, int>{
            while(l >= 0 && r < s.length() && (s[l] == s[r])){
                l--;
                r++;
            }
            if(res.length() < r - l - 1 && l + 1 < s.length()){
                res = s.substr(l + 1, r - l - 1);
            }

            return {l, r};
        };
        while(pMid < s.length()){
            //以pMid为中心
            extendFind(pMid, pMid);
            //中心为空
            extendFind(pMid, pMid + 1);
            pMid++;
        }

        return res;
    }
    //动态规划
    string longestPalindrome_s(string s) {
        string res;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        if(s.length() > 0){
            res.push_back(s[0]);
        }
        for(int i = s.length() - 1; i >= 0; i--){
            dp[i][i] = true;
            for(int j = i + 1; j < s.length(); j++){
                if(j == i + 1){
                    dp[i][j] = s[i] == s[j];
                }else{
                    dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1] == true);
                }
                if(dp[i][j] == true && res.length() < j - i + 1){
                    res = s.substr(i, j - i + 1);
                }
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    cout << s.longestPalindrome("babad")
        << "======================================";
}