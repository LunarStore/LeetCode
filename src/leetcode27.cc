#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pSlw = 0, pHry = 0;
        while(pHry < nums.size()){
            if(nums[pHry] != val){
                nums[pSlw++] = nums[pHry];
            }
            pHry++;
        }

        return pSlw;
    }
};