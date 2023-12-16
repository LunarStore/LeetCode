#include <vector>
using namespace std;

//两次二分
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int front = -1, back = -1;
        int begin = 0, end = nums.size() - 1, pos = -1;

        //最后一个小于target的数
        while(begin <= end){
            int mid = (begin + end) / 2;

            if(nums[mid] >= target){
                end = mid - 1;
            }else{
                pos = mid;
                begin = mid + 1;
            }
        }

        front = pos;
        begin = front + 1;
        end = nums.size() - 1;
        pos = nums.size();
        //第一个大于target的数
        while(begin <= end){
            int mid = (begin + end) / 2;
            if(nums[mid] <= target){
                begin = mid + 1;
            }else{
                pos = mid;
                end = mid - 1;
            }
        }
        back = pos;
        if(back > front + 1){
            return {front + 1, back - 1};
        }else{
            return {-1, -1};
        }
    }
};