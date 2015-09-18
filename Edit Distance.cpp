class Solution {
public:
//https://leetcode.com/problems/edit-distance/
//http://blog.163.com/gjx_12358@126/blog/static/895363452014232191498/
//讲解非常详细。
    int minDistance(string word1, string word2) {
        int row=word1.length()+1;
        int col=word2.length()+1;
        //为了初始化，从0到某个值一直就为某个值，见下面的初始化
        vector<vector <int> > f(row,vector<int>(col));
        //vector<vector <int> > f(row,vector<int>(col));
        
        for(int i=0;i<row;i++)
            f[i][0]=i;
        for(int i=0;i<col;i++)
            f[0][i]=i;
        //初始化完毕
        
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                //如果相等
                if(word1[i-1]==word2[j-1])
                    f[i][j]=f[i-1][j-1];
                else{
                    f[i][j]=f[i-1][j-1]+1;//替换的情况
                }
                //真正开始比较的时候
                f[i][j]=min(f[i][j],min(f[i][j-1]+1,f[i-1][j]+1));
                           //删除          插入       刚刚的替换    
            }
        }
        return f[row-1][col-1];
    }
};
