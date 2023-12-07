#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin = 0, end = height.size() - 1;
        int res = 0;
        while(begin < end){
            res = max(res, min(height[begin], height[end]) * (end - begin));

            if(height[begin] < height[end]){
                begin++;
            }else{
                end--;
            }
        }

        return res;
    }
};