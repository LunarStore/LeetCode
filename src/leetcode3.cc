#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> dict(256, false);
        // 滑动窗口
        int front = 0;
        int back = 0;
        int res = 0;
        while (back < s.length()) {

            if (!dict[s[back]]) {
                // 窗口扩张
                dict[s[back]] = true;
                back++;

                res = max(res, back - front);
            } else {
                // 窗口收缩
                dict[s[front]] = false;
                front++;
            }
        }

        return res;
    }
};

int main() {

    cout << "hello world!" << endl;
    return 0;
}