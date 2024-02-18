#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//栈 + 滑动窗口
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        string res;
        int front = 0, back = 0;
        while(front < path.length()){
            if(back == path.length() || path[back] == '/'){
                string fileName = path.substr(front, back - front);
                if(fileName == "."){

                }else if(fileName == ".."){
                    if(!stk.empty()) 
                        stk.pop_back();
                }else if(!fileName.empty()){
                    // 文件名
                    stk.push_back(fileName);
                }// else  fileName is empty

                front = back + 1;
            }
            back++;
        }

        for(auto &it : stk){
            res += "/" + it;
        }

        return res == "" ? "/" : res;
    }
};