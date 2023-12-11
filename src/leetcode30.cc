#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


//leetcode超时，未通过
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int baseLen = words.back().length();
        unordered_map<string, int> hashMap;
        vector<int> res;

        for(auto it : words){
            hashMap[it]++;
        }
        for(int start = 0; start < baseLen; start++){
            unordered_map<string, int> cmp = hashMap;
            int front = start, back = start;

            while(back < s.length()){
                string curWord = s.substr(back, baseLen);
                auto itr = cmp.find(curWord);
                if(itr == cmp.end()){
                    //快滑
                    back = back + baseLen;
                    front = back;
                    cmp.clear();
                    cmp = hashMap;
                    continue;
                }else if(itr->second > 0){
                    //窗口扩大
                    itr->second--;
                    back = back + baseLen;

                }else if(itr->second <= 0){
                    //窗口收缩
                    cmp[s.substr(front, baseLen)]++;
                    front = front + baseLen;
                }

                if(check(cmp) == true){
                    res.push_back(front);
                }

            }
        }

        return res;
    }
private:
    bool check(unordered_map<string, int> hm){
        for(auto &it : hm){
            if(it.second != 0){
                return false;
            }
        }

        return true;
    }
};

int main(){

    Solution s;
    string str = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","word"};
    s.findSubstring(str, words);
    return 0;
}