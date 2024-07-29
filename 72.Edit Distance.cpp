class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(), n=word2.size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, INT_MAX));

        for(int i=0; i<=m; i++){
            dp[i][0]=i;
        }
        for(int j=0; j<=n; j++){
            dp[0][j]=j;
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1]!=word2[j-1]){
                    dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                }
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};
/*
// 替换 删除 插入  把三个过程分开 就很简单了
				dp[i][j]=dp[i-1][j-1]+1;//替换
				//删除 word1[i-1] word1[0..i-2]--word2[0..j-1]
				// 插入 word2[j-1]  word1[0..i-1]+word2[j-1] -- word2[0..j-1]   这个时候一目了然
*/
//为自己点赞 一下子ac啦
//加油，意思明白，只是感觉题目好奇怪啊，题目还是蛮奇怪的，但是真正做下去，还是很有意思的
