#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0, end = 0;
        int res = 0;
        vector<bool> hashMap(128, false);
        while(end < s.length()){
            if(hashMap[s[end]] == false){
                //加入end字符无重复，窗口扩展
                hashMap[s[end]] = true;
                end++;
                res = max(res, end - begin);
            }else{
                //否则，有重复，就将窗口缩小
                hashMap[s[begin]] = false;
                begin++;
            }
        }

        return res;
    }
};