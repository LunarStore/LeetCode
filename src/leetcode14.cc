#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //暴力扫描
        string res;
        if(strs.empty()){
            return "";
        }
        for(int i = 0; i < strs[0].length(); i++){
            int j;
            for(j = 1; j < strs.size(); j++){
                if(strs[j][i] != strs[0][i]){
                    break;
                }
            }

            if(j == strs.size()){
                res.push_back(strs[0][i]);
            }else{
                break;
            }
        }

        return res;
    }
};