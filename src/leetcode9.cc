#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string num = to_string(x);
        int begin = 0, end = num.size() - 1;
        while(begin < end){
            if(num[begin] == num[end]){
                begin++;
                end--;
            }else{
                return false;
            }
        }

        return true;
    }
};