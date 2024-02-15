#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 该算法在LevelDB中有应用。
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int start = -1, end = -1;
        // 先按start排好序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs)->bool{
            return lhs.front() < rhs.front();
        });


        for(int i = 0; i < intervals.size(); i++){
            // end < start作为重启点的标志
            if (end < intervals[i].front()){    // 不重叠
                if(i != 0){   // 去除首个无用数据。
                    res.push_back({start, end});
                }
                start = intervals[i].front();
                end = intervals[i].back();

            }else{  // end >= intervals[i].front()  // 重叠了更新end
                end = max(end, intervals[i].back());
            }
        }

        if(!intervals.empty()){ // 最后一个区间
            res.push_back({start, end});
        }
        return res;
    }
};

int main(){

    return 0;
}