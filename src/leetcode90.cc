#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
    void backTrace(vector<int>& nums, int index, vector<int>& temp, vector<vector<int>> &out) {
        out.push_back(temp);
        if(index >= nums.size()) {
            return;
        }

        for(int i = index; i < nums.size(); i++) {
            if((i != index) && (nums[i] == nums[i - 1])) {
                continue;
            }
            temp.push_back(nums[i]);
            backTrace(nums, i + 1, temp, out);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        sort(nums.begin(), nums.end());
        backTrace(nums, 0, temp, res);

        return res;
    }
};