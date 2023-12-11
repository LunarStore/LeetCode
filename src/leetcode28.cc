#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void getNext(string target, vector<int>& next){
        int pSlw, pHry;
        pSlw = -1;   //零下标处失配，就去和-1下标对比，-1下标代表万能字符。
        pHry = 0;
        next[0] = -1;
        while(pHry < target.length() - 1){
            if(pSlw == -1 || target[pSlw] == target[pHry]){
                next[++pHry] = ++pSlw;
            }else{
                //pSlw回溯
                pSlw = next[pSlw];
            }
        }
    }
    int strStr(string haystack, string needle) {
        vector<int> next(needle.length());
        int pHay = 0, pNee = 0;
        getNext(needle, next);

        while(pHay < (int)haystack.length() && pNee < (int)needle.length()){
            if(pNee == -1 || haystack[pHay] == needle[pNee]){
                pHay++;
                pNee++;
            }else{
                pNee = next[pNee];
            }
        }

        if(pNee < needle.length()){
            return -1;
        }else{
            return pHay - pNee;
        }
    }
};

int main(){
    Solution s;
    s.strStr("leetcode", "leeto");
    return 0;
}