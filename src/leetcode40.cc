#include <vector>
#include <algorithm>
using namespace std;

// 有可能重复、同一元素选取一次、求组合、chandidates[index] > 0
class Solution {
private:
    void backTrace(vector<int> &candidates, vector<vector<int>>& out, vector<int> &temp, int index, int sum, int target){
        if(sum >= target){
            if(sum == target) out.push_back(temp);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(i != index && candidates[i] == candidates[i - 1]) continue;
            temp.push_back(candidates[i]);
            backTrace(candidates, out, temp, i + 1, sum + candidates[i], target);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        backTrace(candidates, res, temp, 0, 0, target);
        return res;
    }
};