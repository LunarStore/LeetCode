#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> m_numToAlph = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string temp;
        if(digits.length() == 0){
            return res;
        }
        backTrace(digits, 0, temp, res);
        return res;
    }
private:
    void backTrace(string& digits, int pos, string& temp, vector<string>& out){
        if(pos >= digits.length()){
            out.push_back(temp);
            return;
        }
        string& alphs = m_numToAlph[digits[pos] - '0'];
        for(int i = 0; i < alphs.length(); i++){
            temp.push_back(alphs[i]);
            backTrace(digits, pos + 1, temp, out);
            temp.pop_back();
        }

        return;
    }
};