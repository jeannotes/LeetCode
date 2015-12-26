class Solution {
public:
//斐波那契数列，下一个数，要么之前一位的，要么之前两位的。
    int climbStairs(int n) {
        int sum[n+1];
        sum[0]=1;
        sum[1]=1;
        for(int i=2;i<=n;i++){
            sum[i]=sum[i-1]+sum[i-2];
        }
        return sum[n];
    }
};
