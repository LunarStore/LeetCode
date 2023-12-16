#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        int pos = nums.size();
        while(begin <= end){
            int mid = (begin + end) / 2;

            if(nums[mid] < target){
                begin = mid + 1;
            }else{
                pos = mid;
                end = mid - 1;
            }
        }
        
        return pos;
    }
};