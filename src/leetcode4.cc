#include <vector>
using namespace std;

class Solution {
public:
    //这题，偷个懒把，直接归并完事了。
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        vector<int> temp;
        temp.reserve(nums1.size() + nums2.size());

        while(p1 < nums1.size() && p2 < nums2.size()){
            if(nums1[p1] < nums2[p2]){
                temp.push_back(nums1[p1]);
                p1++;
            }else{
                temp.push_back(nums2[p2]);
                p2++;
            }
        }

        while(p1 < nums1.size()) temp.push_back(nums1[p1++]);
        while(p2 < nums2.size()) temp.push_back(nums2[p2++]);

        return temp.size() % 2 == 1 ? temp[temp.size() / 2] : ((double)temp[temp.size() / 2] + temp[temp.size() / 2 - 1]) / 2;
    }
};