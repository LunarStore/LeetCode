#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < dp.size(); i++){
            for(int start = 0; start < i; start++){
                if(start + nums[start] >= i && dp[start] + 1 < dp[i]){
                    dp[i] = dp[start] + 1;
                }
            }
        }

        return dp.back();
    }
};