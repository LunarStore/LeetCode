#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.length() <= 1) {
            assert(s2.length() == s1.length());

            // m_map[s1 + "&" + s2] = s1 == s2;
            return s1 == s2;
        }
        auto res = m_map.find(s1 + "&" + s2);
        if(res != m_map.end()) {
            return res->second;
        }

        for(int i = 1; i < s1.length(); i++) {
            string left = s1.substr(0, i);
            string right = s1.substr(i, string::npos);

            if((isScramble(left, s2.substr(0, i)) && isScramble(right, s2.substr(i, string::npos))) ||
                (isScramble(right, s2.substr(0, right.length())) && isScramble(left, s2.substr(right.length(), string::npos)))
                ) {
                
                m_map[s1 + "&" + s2] = true;
                return true;
            }
        }
        m_map[s1 + "&" + s2] = false;
        return false;
    }
    std::unordered_map<string, bool> m_map;
};