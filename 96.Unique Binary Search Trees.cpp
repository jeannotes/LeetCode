class Solution {
public:
//https://leetcode.com/problems/unique-binary-search-trees/
    int numTrees(int n) {
        //https://leetcode.com/problems/unique-binary-search-trees/
        // f(n)=f(0)*f(n-1)+f(1)*f(n-2)+f(2)*f(n-3)+...+f(n-1)*f(0)
        //f(n)--代表左半边有几个数
        //f(1)=f(0)*f(0)   f(2)=f(0)*f(1)+f(1)*f(0)
        //f(3)=f(0)*f(2)+f(1)*f(2)+f(2)*f(0)
        if(n==1) return 1;
        vector<int>dp(n+1, 0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++){
            for(int j=0; j<i; j++)
                dp[i] += dp[j]*dp[i-j-1];
        }
        return dp[n];
    }
};
//初始化一定要赋值
//赋值！！！
//别忘了sum[0]=1，哈哈，一次AC
// 如果写成--sum[0]=1;  这样的话sum[i]+=sum[j]*sum[i-1-j];每次就会多加数字
