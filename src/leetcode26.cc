#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pSlw = 1, pHry = 1;

        while(pHry < nums.size()){
            if(nums[pHry] != nums[pHry - 1]){
                nums[pSlw++] = nums[pHry];
            }
            pHry++;
        }
        return pSlw;
    }
};