#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pSlw = 2, pHry = 2;
        if(nums.size() < 2) return nums.size();
        while(pHry < nums.size()){
            if(nums[pSlw - 2] != nums[pHry]){
                nums[pSlw++] = nums[pHry];
            }

            pHry++;
        }

        return pSlw;
    }
};