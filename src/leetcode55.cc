#include <vector>

#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dist = 0;

        for(int i = 0; i < nums.size(); i++){
            if(dist >= i){
                // 更新可以跳跃的最大距离
                dist = max(dist, i + nums[i]);
            }else{
                // 借助前面可以借助的点，没有一个可以达到该点。说明本就无法达到终点。
                return false;
            }
        }

        return true;
    }
};