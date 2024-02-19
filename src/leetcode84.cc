#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        vector<pair<int, int>> borders(heights.size(), make_pair(-1, heights.size()));
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            while(!stk.empty() && heights[i] < heights[stk.top()]){
                borders[stk.top()].second = i;
                stk.pop();
            }

            if(!stk.empty()){
                if(heights[i] == heights[stk.top()]){
                    borders[i].first = borders[stk.top()].first;
                }else{
                    borders[i].first = stk.top();
                }
            }
            stk.push(i);
        }

        for(int i = 0; i < borders.size() ; i++){
            res = max(res, heights[i] * (borders[i].second - borders[i].first - 1));
        }

        return res;
    }
};