#include <vector>
#include <algorithm>
using namespace std;

// first + second + third == target
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res;
        sort(nums.begin(), nums.end());

        for(int first = 0; first < nums.size(); first++){
            int towTarget = target - nums[first];
            int second = first + 1;
            int third = nums.size() - 1;

            if(first != 0 && nums[first] == nums[first - 1]) continue;
            while(second < third){
                int num1 = nums[first], num2 = nums[second], num3 = nums[third];
                if(abs(target - res) > abs(target - (num1 + num2 + num3))) {
                    res = num1 + num2 + num3;
                }
                if(nums[second] + nums[third] > towTarget){
                    third--;
                }else if(nums[second] + nums[third] < towTarget){
                    second++;
                }else{
                    return res;
                }

                while(second < third && nums[second] == num2) second++;
                while(second < third && nums[third] == num3) third--;
            }
        }

        return res;
    }
};