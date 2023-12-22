#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    void backTrace(vector<vector<int>>& out, vector<int>& nums, vector<int>& temp){
        if(temp.size() == nums.size()){
            out.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == INT_MIN || i != 0 && nums[i - 1] != INT_MIN && nums[i - 1] == nums[i]) continue;
            
            int num = nums[i];
            nums[i] = INT_MIN;
            temp.push_back(num);

            backTrace(out, nums, temp);

            temp.pop_back();
            nums[i] = num;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backTrace(res, nums, temp);
        return res;
    }
};