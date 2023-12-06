#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //key：num，value：index
        unordered_map<int, int> hashMap;

        for(int i = 0; i < nums.size(); i++){
            auto itr = hashMap.find(target - nums[i]);
            if(itr != hashMap.end()){
                //另一半存在
                return {itr->second, i};
            }else{
                //另一半不存在
                hashMap[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};