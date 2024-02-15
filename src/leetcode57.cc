#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 用二分或者直接一次遍历
// 严谨思考！！
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i;
        // if(intervals.empty()) res.push_back(newInterval);
        for(i = 0; i < intervals.size() ; i++){
            if(intervals[i].back() < newInterval.front()){  // 在左边
                res.push_back(intervals[i]);
            }else if (intervals[i].front() > newInterval.back()){   // 在右边
                //res.push_back(intervals[i]);
                break;
            }else{  // 有重叠
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        res.insert(res.end(), intervals.begin() + i, intervals.end());
        return res;
    }
};