#include <vector>

using namespace std;

// 无重复、同一元素无限制选取、求组合、chandidates[index] > 0
class Solution {
private:
    void backTrace(vector<int> &candidates, vector<vector<int>>& out, vector<int> &temp, int index, int sum, int target){
        if(sum >= target){
            if(sum == target) out.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            backTrace(candidates, out, temp, i, sum + candidates[i], target);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backTrace(candidates, res, temp, 0, 0, target);
        return res;
    }
};