#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 1; i < n; i++){
            //滑动窗口
            int front = 0, back = 0;
            string temp;
            while(front < res.length()){
                if(back < res.length() && res[front] == res[back]){
                    //窗口扩张
                    back++;
                }else{
                    //窗口收缩
                    temp.append(to_string(back - front)); // 个数
                    temp.push_back(res[front]);
                    front = back;
                }
            }
            res.swap(temp);
        }

        return res;
    }
};