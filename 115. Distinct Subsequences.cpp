// 之前理解有误，单从字面理解，可以想为，s中字符删减多少次变成t中的字符
//但写代码的时候还是不能够按照这种方法来理解，只是由给的列子来看，还是使用删减法来理解最好不过
//还是有问题
// 不能理解为删减多少次，这样 dp[i][0]=1; 无法解释，就是出现次数 解释比较好
class Solution {
public:
    static const int MOD= 1e9+7;
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        dp[0][0]=1;
        for(int i=1; i<=n; i++) dp[i][0]=1;
        for(int j=1; j<=m; j++) dp[0][j]=0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
                else
                    dp[i][j]=(dp[i-1][j])%MOD;
            }
        }
        return dp[n][m];
    }
};
// https://leetcode.com/discuss/2143/any-better-solution-that-takes-less-than-space-while-in-time
// 容易出错，加油
// 这道题目似乎用递归的方法更加能够理解啊
//再说一下，用递归的方法容易理解啊,还是不会啊，递归是个好方法
//http://www.cnblogs.com/TenosDoIt/p/3440022.html
