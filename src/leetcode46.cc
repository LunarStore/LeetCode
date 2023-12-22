#include <vector>

using namespace std;

//无重复，求排列
class Solution {
    void backTrace(vector<vector<int>>& out, vector<int>& nums, int index){
        if(index == nums.size()){
            out.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            backTrace(out, nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backTrace(res, nums, 0);
    }
};