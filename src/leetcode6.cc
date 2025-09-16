#include <string>

using namespace std;

/**
 * 找规律
 */
class Solution {
public:
    string convert(string s, int numRows) {
        string res;

        if (numRows == 1) return s;
        
        for (int i = 0; i < numRows; i++) {
            int cur = i;
            while(cur < s.length()) {
                if (i == 0 || i == numRows - 1) {
                    res.push_back(s[cur]);
                } else {
                    int offset = cur + 2 * (numRows - i - 1);
                    res.push_back(s[cur]);

                    if (offset < s.length())
                        res.push_back(s[offset]);
                }
                cur += numRows*2 - 2;
            }
        }

        return res;
    }
};