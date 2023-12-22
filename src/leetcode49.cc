#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hashMap;
        vector<vector<string>> res;

        for(auto &its : strs){
            string temp = its;
            sort(temp.begin(), temp.end());

            auto itm = hashMap.find(temp);
            if(itm == hashMap.end()){
                itm = hashMap.insert(make_pair(temp, res.size())).first;
                res.push_back(vector<string>());
            }

            res[itm->second].push_back(its);
        }

        return res;
    }
};