#include <string>
#include <vector>
using namespace std;

/**
 * dp数组含义：
 *  - i代表s串开始下标。
 *  - j代表s串结尾下标。
 *  - dp[i][j]代表s串当中，[i, j]这段字符串是否为回文字符串。
 * 
 * 初始条件：
 *  - dp数组当中 i == i 的位置必定为true。即：一个字符必定为回文字符串。
 *  - dp数组当中 j == i + 1 的位置仅当s[i] == s[j]时为回文字符串。即：
 *      长度为2的字符串，仅当两个字符相等时为回文字符串。
 * 
 * 状态迁移：
 *  - 当dp[i + 1][j - 1]为true，且s[i] == s[j]时判定 [i, j]为回文字符串。
 *      即：s字符串当中，只有[i + 1, j - 1]为回文字符串，且s[i] == s[j]时，
 *      我们就认为[i, j]这段字符串为合法回文字符串。
 */
class Solution {
public:
    string longestPalindrome(string s) {
        // 动态规划
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));

        string res;
        for (int i = dp.size() - 1; i >= 0; i--) {
            dp[i][i] = true;
            if (res.length() < 1) {
                res = s.substr(i, 1);
            }
            for (int j = i + 1; j < dp[0].size(); j++) {
                if (j == i + 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                }

                if (dp[i][j] && (j - i + 1) > res.length()) {
                    res = s.substr(i, j - i + 1);
                }
            }
        }

        return res;
    }
};