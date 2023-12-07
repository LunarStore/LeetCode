#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> toInt = {{"M", 1000}, 
            {"CM", 900}, 
            {"D", 500}, 
            {"CD", 400}, 
            {"C", 100}, 
            {"XC", 90}, 
            {"L", 50}, 
            {"XL", 40}, 
            {"X", 10}, 
            {"IX", 9}, 
            {"V", 5}, 
            {"IV", 4}, 
            {"I", 1}};
        int pos = 0, res = 0;
        while(pos < s.length()){
            if(pos + 1 < s.length() && toInt.find(s.substr(pos, 2)) != toInt.end()){
                res += toInt[s.substr(pos, 2)];
                pos += 2;
            }else{
                res += toInt[s.substr(pos, 1)];
                pos += 1;
            }
        }
        return res;
    }
};