class Solution {
    //https://leetcode.com/discuss/43398/20ms-detailed-explained-c-solutions-o-n-space
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>>res(m+1,vector<int>(n+1,0));
        res[0][0]=0;
        //res[i][j]--s1[0...i-1]--s2[0...j-1]
        //初始化
        for(int i=1;i<=m;i++)
            res[i][0]=i;//好题目的，一下子做出来
        
        for(int i=1;i<=n;i++)
            res[0][i]=i;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    res[i][j]=res[i-1][j-1];
                else{
                    res[i][j]=res[i-1][j-1]+1;
                    
                    int tem=min(res[i][j-1]+1,res[i-1][j]+1);
                    res[i][j]=min(res[i][j],tem);
                }
            }
        }
        
        return res[m][n];
    }
};
//不会，重新更新了一下，主要分成相等以及不相等的情况， 好题目 
/*
// 替换 删除 插入
				dp[i][j]=dp[i-1][j-1]+1;//替换
				//删除 word1[i-1] word1[0..i-2]--word2[0..j-1]
				// 插入 word2[j-1]  word1[0..i-1]+word2[j-1] -- word2[0..j-1]   这个时候一目了然
*/
//为自己点赞 一下子ac啦
//加油，意思明白，只是感觉题目好奇怪啊，题目还是蛮奇怪的，但是真正做下去，还是很有意思的
