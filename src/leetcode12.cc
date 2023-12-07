#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> toRoman = {{1000, "M"}, 
            {900, "CM"}, 
            {500, "D"}, 
            {400, "CD"}, 
            {100, "C"}, 
            {90, "XC"}, 
            {50, "L"}, 
            {40, "XL"}, 
            {10, "X"}, 
            {9, "IX"}, 
            {5, "V"}, 
            {4, "IV"}, 
            {1, "I"}};
        string res;
        for(int i = 0; i < toRoman.size(); i++){
            while(num >= toRoman[i].first){
                res.append(toRoman[i].second);
                num = num - toRoman[i].first;
            }
        }

        return res;
    }
};