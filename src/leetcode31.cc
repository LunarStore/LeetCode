#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size() - 2, tPos = 0;

        while(pos >= 0){
            if(nums[pos] >= nums[pos + 1]){
                pos--;
                continue;
            }else{
                break;
            }
        }
        if(pos != -1){
            tPos = nums.size() - 1;
            while(tPos >=0){
                if(nums[tPos] > nums[pos]){
                    break;
                }else{
                    tPos--;
                }
            }
            swap(nums[pos], nums[tPos]);
        }
        
        reverse(nums.begin() + pos + 1, nums.end());
    }
};