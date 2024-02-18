#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
    void backTrace(int index, vector<int> &nums, vector<int> &temp, vector<vector<int>> &out){
        out.push_back(temp);
        if(index >= nums.size()){
            return;
        }

        for(int i = index; i < nums.size(); i++){
            temp.push_back(nums[i]);
            backTrace(i + 1, nums, temp, out);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        backTrace(0, nums, temp, res);
        return res;
    }
};