#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    void backTrace(string &s, int index, int count, string &temp, vector<string> &out) {
        if(index >= s.length() && count == 5){
            out.push_back(temp.substr(0, temp.length() - 1));
            return;
        }else if (count > 4) {
            return;
        }
        int end = temp.length();
        if(s[index] == '0') {
            // 零开头，只能为0
            temp.push_back(s[index]);
            temp.push_back('.');
            backTrace(s, index + 1, count + 1, temp, out);

            temp.pop_back();
        } else {
            int num = 0;
            for(int i = index; i < s.length(); i++) {
                num = num *10 + s[i] - '0';
                if(num > 255) {
                    break;
                }
                temp.push_back(s[i]);
                temp.push_back('.');
                backTrace(s, i + 1, count + 1, temp, out);
                temp.pop_back();
            }
        }

        temp.resize(end);
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string temp;
        backTrace(s, 0, 1, temp, res);
        return res;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
};