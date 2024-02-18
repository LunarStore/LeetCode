#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial = {1,1,2,6,24,120,720,5040,40320};
        vector<bool> hash(n + 1, false);
        string res;
        int curK = 0;
        for(int i = 1; i <= n; i++){    // 确定第i位

            for(int j = 1; j <= n; j++){    // 贪心，取最小且满足条件的。
                if(hash[j] == true) continue;   // 用了

                int nextCurK = curK + factorial[n - i];
                if(nextCurK >= k){
                    // 找到
                    res.push_back(j + '0');
                    hash[j] = true; // 被使用。
                    break;
                }

                curK = nextCurK;
            }
        }

        return res;
    }
};