#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int first = 0; first < nums.size(); first++){
            int target = -nums[first];
            int second = first + 1;
            int third = nums.size() - 1;

            if(first != 0 && nums[first] == nums[first - 1]) continue;
            while(second < third){
                if(nums[second] + nums[third] > target){
                    third--;
                }else if(nums[second] + nums[third] < target){
                    second++;
                }else{
                    res.push_back({nums[first], nums[second], nums[third]});
                    int num1 = nums[second], num2 = nums[third];

                    while(second < third && nums[second] == num1) second++;
                    while(second < third && nums[third] == num2) third--;
                }
            }
        }

        return res;
    }
};