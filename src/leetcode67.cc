#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int spill = 0;
        int pa = a.size() - 1, pb = b.size() - 1;

        while(pa >= 0 || pb >= 0 || spill != 0){
            int num = spill;
            if(pa >= 0){
                num += a[pa] - '0';
                pa--;
            }

            if(pb >= 0){
                num += b[pb] - '0';
                pb--;
            }
            res.push_back((num % 2) + '0');
            spill = (num / 2);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};