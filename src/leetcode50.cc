#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        int64_t cmp = n;
        double res = 1;
        bool flag = n > 0 ? false : true;
        if(flag == true){
            cmp = -cmp;
        }
        int64_t count = 1;

        while(count <= cmp){
            if((count & cmp) > 0){
                res = res * x;
            }
            x = x * x;
            count = count << 1;
        }

        return flag == false ? res : (1.0 / res);
        
    }
};