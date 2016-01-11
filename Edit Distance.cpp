class Solution {
    //http://www.tuicool.com/articles/iAzEbm
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>>res(m+1,vector<int>(n+1,0));
        res[0][0]=0;
        //res[i][j]--s1[0...i-1]--s2[0...j-1]
        //初始化
        for(int i=1;i<=m;i++)
            res[i][0]=i;//
        
        for(int i=1;i<=n;i++)
            res[0][i]=i;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    res[i][j]=res[i-1][j-1];
                else
                    res[i][j]=res[i-1][j-1]+1;//替换
                
                int tem=min(res[i][j-1]+1,res[i-1][j]+1);
                res[i][j]=min(res[i][j],tem);
            }
        }
        
        return res[m][n];
    }
};
