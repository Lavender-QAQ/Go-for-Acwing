class Solution {
public:
    int climbStairs(int n) {
        int f[48]={1,2};
        for(int i=2;i<48;i++){
            f[i]=f[i-1]+f[i-2];
        }
        return f[n-1];
    }
};
