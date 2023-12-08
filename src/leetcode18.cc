#include <vector>
#include <algorithm>
#include <stdint.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int four = 0; four < nums.size(); four++){
            if(four != 0 && nums[four] == nums[four - 1]) continue;
            for(int first = four + 1; first < nums.size(); first++){
                int64_t towTarget = (int64_t)target - (nums[first] + nums[four]);
                int second = first + 1;
                int third = nums.size() - 1;

                if(first != (four + 1) && nums[first] == nums[first - 1]) continue;
                while(second < third){
                    if(nums[second] + nums[third] > towTarget){
                        third--;
                    }else if(nums[second] + nums[third] < towTarget){
                        second++;
                    }else{
                        res.push_back({nums[first], nums[second], nums[third], nums[four]});
                        int num1 = nums[second], num2 = nums[third];

                        while(second < third && nums[second] == num1) second++;
                        while(second < third && nums[third] == num2) third--;
                    }
                }
            }
        }

        return res;
    }
};