#include <vector>
using namespace std;

//dp[i]为以下标i结尾的子数组和最大是多少。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], cur = 0;
        for(auto it : nums){
            cur = max(cur + it, it);
            res = max(res, cur);
        }

        return res;
    }
};