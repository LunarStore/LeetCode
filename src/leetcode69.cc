class Solution {
public:
    int mySqrt(int x) {
        long long begin = 0, end = x;

        while(begin < end){
            long long mid = (begin + end) / 2;

            if(mid * mid <= x){
                begin = mid;
            }else{
                end = mid - 1;
            }
        }

        return begin;
    }
};