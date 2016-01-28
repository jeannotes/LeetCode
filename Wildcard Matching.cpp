class Solution1 {
    //和regular expression matching的区别在于他不需要判断在这个之前的一个字符与前面的相同，他是任意的。
public:
    bool isMatch(string s, string p) {
        //这个方法就是向后看的，接下来的一段都可以与*匹配
        char *ss=&s[0];char *pp=&p[0];
        char *start=NULL,*rs=NULL;
        
        while(*ss!='\0'){
            if(*ss==*pp||*pp=='?'){
                ss++;pp++;
                continue;
            }
            
            if(*pp=='*'){
                start=pp;
                pp++;//这个时候从下一位开始匹配，因为之前的p可以匹配0位的，1位的....
                rs=ss;
                continue;
            }
            
            //上面两种情况都不符合，那就让之前的*来匹配
            if(start!=nullptr){
                pp=start+1;
                ss=rs;//从第0位开始匹配
                rs++;
                continue;
            }
            
            return false;
        }
        
        while(*pp=='*'){
            pp++;
        }
        return *pp=='\0';
    }
};



class Solution2 {
//https://leetcode.com/problems/wildcard-matching/
//动态规划
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool> >dp(m+1,vector<bool>(n+1,false));
        
        dp[0][0]=true;
        //  dp[i][j] 代表s[0..i-1]与p[0...j-1]是否匹配
        for(int i=1;i<=n;i++){
            dp[0][i] = p[i-1]=='*' && dp[0][i-1];
        }//这个时候i=0，还没有进入s，只有 p[j-1]=='*' 且dp[0][j-1] 才行
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j]||dp[i][j-1] ;
                    //按照道理，应该是
                    //dp[i][j]  = dp[i][j-1]||dp[i-1][j-1]||dp[i-2][j-1]||dp[i-3][j-1] ||....||dp[0][j-1]
                    //             匹配0个      匹配1个       匹配2个       匹配3个
                    //dp[i-1][j]= dp[i-1][j-1]||dp[i-2][j-1]||dp[i-3][j-1] ||....||dp[0][j-1]
                    //             匹配0个      匹配1个       匹配2个       
                    //所以dp[i][j] = dp[i-1][j]||dp[i][j-1] 
                    //只是每次迭代其实dp[i-1][j-1]已经把后面那部分算过了。
                } 
                else if(p[j-1]=='?'||s[i-1]==p[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
            }
        }
        
        return dp[m][n];
    }
};
