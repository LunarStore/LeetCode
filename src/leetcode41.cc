#include <vector>

using namespace std;

//原地hash
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            while(i + 1 != nums[i] && nums[i] > 0){
                if(nums[i] - 1 < nums.size() && nums[nums[i] - 1] != nums[i]) {
                    swap(nums[i], nums[nums[i] - 1]);
                }else{
                    break;
                }

            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};