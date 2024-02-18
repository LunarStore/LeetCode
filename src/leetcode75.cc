#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pRed = 0, pBlue = nums.size() - 1;
        int p = 0;

        while(p <= pBlue){
            if(nums[p] == 0){
                swap(nums[pRed], nums[p]);
                pRed++;
                if(p < pRed){
                    p = pRed;
                }
            }else if(nums[p] == 2){
                swap(nums[pBlue], nums[p]);
                pBlue--;
            }else{
                p++;
            }
        }
    }
};