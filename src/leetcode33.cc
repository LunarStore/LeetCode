#include <vector>
using namespace std;


//分情况进行二分讨论
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;

        while(begin <= end){
            int mid = (begin + end) / 2;

            if(nums[mid] > target){
                //分情况讨论mid是属于哪一部分
                if(nums[mid] >= nums[begin]){
                    // 在大段
                    //继续判断target是在打段还是在小段
                    if(target > nums[begin]){
                        end = mid - 1;
                    }else if(target < nums[begin]){
                        begin = mid + 1;
                    }else{
                        return begin;
                    }
                }else{
                    //在小段
                    end = mid - 1;
                }
            }else if(nums[mid] < target){
                //同样分情况讨论mid属于那一部分
                if(nums[mid] >= nums[begin]){
                    //在大段
                    begin = mid + 1;
                }else{
                    //在小段
                    if(target > nums[end]){
                        end = mid - 1;
                    }else if(target < nums[end]){
                        begin = mid + 1;
                    }else{
                        return end;
                    }
                }
            }else{
                return mid;
            }
        }
        return -1;
    }
};