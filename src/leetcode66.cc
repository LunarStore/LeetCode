#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.size() + 1, 0);
        int spill = 0;
        res[res.size() - 1] = 1;
        for(int i = 0; i < digits.size(); i++){
            int num = digits[digits.size() - 1 - i] + res[res.size() - 1 - i] + spill;
            res[res.size() - 1 - i] = num % 10;

            spill = num /  10;
        }

        if(spill != 0){
            res[0] = 1;
        }
        int pos = 0;
        while(pos < res.size() && res[pos] == 0) pos++;

        return pos < res.size() ? vector<int>(res.begin() + pos, res.end()) : vector<int>(1, 0);
    }
};