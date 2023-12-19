#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //单调栈，求左右两边大于自身，且最小的边界  false
        //求左右两边最大的边，不要求最近 true
        vector<pair<int, int>> maxs(height.size(), make_pair(-1, height.size()));
        int res = 0;
        int left = -1, right = height.size();
        for(int i = 0; i < height.size(); i++){
            if(left == -1 || height[i] > height[left]){
                left = i;
            }

            if(right == height.size() || height[(int)height.size() - 1 - i] > height[right]){
                right = (int)height.size() - 1 - i;
            }

            maxs[i].first = left;
            maxs[(int)height.size() - 1 - i].second = right;
        }

        for(int i = 0; i < height.size(); i++){
            res += min(height[maxs[i].first], height[maxs[i].second]) - height[i]; 
        }
        return res;
    }
};