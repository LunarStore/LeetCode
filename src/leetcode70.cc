class Solution {
public:
    int climbStairs(int n) {
        int stage1 = 1, stage2 = 2;
        int res;
        if(n == 1) return 1;
        if(n == 2) return 2;
        for(int i = 3; i <= n; i++){
            res = stage1 + stage2;
            stage1 = stage2;
            stage2 = res;
        }

        return res;
    }
};