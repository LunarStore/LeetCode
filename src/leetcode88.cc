#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1, p2, p = nums1.size() - 1;
        p1 = m - 1;
        p2 = n - 1;

        while(p1 >= 0 && p2 >= 0) {
            if(nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }

            p--;
        }

        if(p2 >= 0) {
            copy(nums2.begin(), nums2.begin() + p2 + 1, nums1.begin());
        }

        return;
    }
};