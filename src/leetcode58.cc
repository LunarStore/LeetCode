#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(isalpha(s[i])){
                while(i >= 0 && isalpha(s[i])){
                    res++;
                    i--;
                }
                break;
            }
        }
        return res;
    }
};