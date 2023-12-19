#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res (num1.length() + num2.length(), '0');    //尽可能多分配，默认为'0'
        for(int i = 0; i < num2.length(); i++){//将num2的每一位都和num1相乘
            int n2 = num2[num2.length() - 1 - i] - '0';     //将char转换成int
            int j = num1.length() - 1;  //num1最低位
            int spill = 0;  //进位
            int pos = res.length() - 1 - i; //每乘一轮就向高位移动一位
            while(j >= 0 || spill != 0){
                int n1 = j >= 0 ? num1[j] - '0' : 0;
                int n = n1 * n2 + spill + res[pos] - '0';
                spill = n / 10;
                res[pos] = n % 10 + '0';
                j--;
                pos--;
            }
        }

        int start = 0;
        while(start < res.length() - 1 && res[start] == '0') start++;   //去除前导零

        return res.substr(start, string::npos);
    }
};

int main(){
    string n1 = "2", n2 = "3";
    Solution s;

    s.multiply(n1, n2);
}