#include <vector>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 一次归并
        vector<int> mergeArr;
        mergeArr.reserve(nums1.size() + nums2.size());
        int p1 = 0;
        int p2 = 0;

        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] < nums2[p2]) {
                mergeArr.push_back(nums1[p1]);
                p1++;
            } else {
                mergeArr.push_back(nums2[p2]);
                p2++;
            }
        }

        if (p1 < nums1.size()) {
            mergeArr.insert(mergeArr.end(), nums1.begin() + p1, nums1.end());
        } else if (p2 < nums2.size()) {
            mergeArr.insert(mergeArr.end(), nums2.begin() + p2, nums2.end());
        }

        return mergeArr.size() % 2 == 0 ? double(mergeArr[(mergeArr.size() - 1) / 2] + mergeArr[(mergeArr.size() - 1) / 2 + 1]) / 2  : mergeArr[mergeArr.size() / 2];
    }
};


int main() {
    Solution s;
    vector v1 = {1, 2};
    vector v2 = {3, 4};
    s.findMedianSortedArrays(v1, v2);

    return 0;
}