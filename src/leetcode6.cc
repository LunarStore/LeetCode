#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string res;

        if(numRows == 1) return s;
        for(int i = 0; i < numRows; i++){
            int pos = i;
            int delta = 2 * (numRows - i) - 2;
            while(pos < s.length()){
                res.push_back(s[pos]);
                if(i > 0 && i < numRows - 1 && pos + delta < s.length()){
                    res.push_back(s[pos + delta]);
                }
                pos = pos + 2 * numRows - 2;
            }
        }

        return res;
    }
};

int main(){

    Solution s;
    s.convert("PAYPALISHIRING", 3);
    return 0;
}