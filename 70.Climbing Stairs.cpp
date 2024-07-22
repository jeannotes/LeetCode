class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int>dp(n,1);
        dp[1]=2;
        for(int i=2; i<n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};
//不会
// 现在能够搞清楚为什么 sum[0]=1;sum[1]=1; 因为一开始作为初始条件，后面第二步要从sum[0]计算的
//基本可以，今晚不做leetcode啦，加油
