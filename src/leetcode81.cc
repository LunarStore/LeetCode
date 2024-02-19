#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;

        while(begin <= end){
            int mid = (begin + end) / 2;

            if(nums[mid] > target){
                if(nums[mid] > nums[begin]){
                    if(nums[begin] > target){
                        begin = mid + 1;
                    }else if(nums[begin] < target){
                        end = mid - 1;
                    }else{
                        return true;
                    }
                }else if(nums[mid] < nums[begin]){
                    end = mid - 1;
                }else{
                    begin++;
                }
            }else if(nums[mid] < target){
                if(nums[mid] < nums[begin]){
                    if(nums[begin] > target){
                        begin = mid + 1;
                    }else if(nums[begin] < target){
                        end = mid - 1;
                    }else{
                        return true;
                    }
                }else if(nums[mid] > nums[begin]){
                    begin = mid + 1;
                }else{
                    begin++;
                }
            }else{
                return true;
            }
        }

        return false;
    }
};