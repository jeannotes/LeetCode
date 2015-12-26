class Solution {
    //http://www.tuicool.com/articles/iAzEbm
    //逆序理解
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>>res(m+1,vector<int>(n+1,0));
        res[0][0]=0;
        
        //res[i][j] --- s1[0....i]->s2[0....j]
        for(int i=1;i<=m;i++) 
            res[i][0]=i;
        for(int i=1;i<=n;i++)
            res[0][i]=i;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                res[i][j]=res[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1);
                
                int tem=min(res[i][j-1]+1,res[i-1][j]+1);
                res[i][j]=min(tem,res[i][j]);
            }
        }
        return res[m][n];
    }
};
