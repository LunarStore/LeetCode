#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
    unordered_map<string, bool> m_memo;
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto it = m_memo.find(s1 + "#" + s2 + "#" + s3);
        if(it != m_memo.end()){
            return it->second;
        }
        if(s1.length() + s2.length() != s3.length()) {
            m_memo[s1 + "#" + s2 + "#" + s3] = false;
            return false;
        }
        if(s1 + s2 == s3) {
            m_memo[s1 + "#" + s2 + "#" + s3] = true;
            return true;
        }

        for(int i = 0; i < s1.length(); i++){
            string s1Left = s1.substr(0, i);
            string s1Right = s1.substr(i, string::npos);
            for(int j = 0; j < s2.length(); j++){
                if(i == 0 && j == 0) continue;
                string s2Left = s2.substr(0, j);
                string s2Right = s2.substr(j, string::npos);
                
                if(isInterleave(s1Left, s2Left, s3.substr(0, s1Left.length() + s2Left.length())) && 
                isInterleave(s1Right, s2Right, s3.substr(s1Left.length() + s2Left.length(), string::npos))){
                    m_memo[s1 + "#" + s2 + "#" + s3] = true;
                    return true;
                }

                if( isInterleave(s2Left, s1Left, s3.substr(0, s1Left.length() + s2Left.length())) &&
                isInterleave(s2Right, s1Right, s3.substr(s1Left.length() + s2Left.length(), string::npos)) ){
                    m_memo[s1 + "#" + s2 + "#" + s3] = true;
                    return true;
                }
            }
        }
        m_memo[s1 + "#" + s2 + "#" + s3] = false;
        return false;
    }
};
int main(){
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
}