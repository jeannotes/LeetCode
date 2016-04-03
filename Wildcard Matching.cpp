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
            if(start!=NULL){//暂时不要管什么null与nullptr的区别了，都能够accepted
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
// 还是不会的，下面来做递归的，两个都不会，加油
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[m][n]=true;
        //dp[i][j]--s[i..m-1]--p[j..n-1]
        for(int i=n-1;i>=0;i--){
            if(p[i]!='*')
                break;
                //这个时候是s中的空格字符，只有p后尾部全部是***才可能配对
                //从后往前，这时候必须每个字符都是*，如果不是的话，那么就必然是false
                //所以这样子下去，p之前的字符没有必要比较，因为只要后面一个字符不是*，不可能匹配的
            else
                dp[m][i]=true;
        }
        //dp[i][j]--s[i..m-1]--p[j..n-1]
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(p[j]==s[i]||p[j]=='?')
                    dp[i][j]=dp[i+1][j+1];
                else if(p[j]=='*')
                //注意，这段程序最好分成三段，如果 第二个地方最好写成else if，如果不写，第一个条件满足了，万一
                //第二个条件有满足，自然程序出错，比如说 1*4 2*3
                    dp[i][j]=dp[i+1][j]||dp[i][j+1];
                    //dp[i][j]  =dp[i][j+1]  ||dp[i+1][j+1]||dp[i+2][j+1]||dp[i+3][j+1]||..
                    //dp[i+1][j]=dp[i+1][j+1]||dp[i+2][j+1]||dp[i+3][j+1]||..
                    // so -> dp[i][j]=dp[i+1][j]||dp[i][j+1];
                else
                    dp[i][j]=false;
            }
        }
        return dp[0][0];
    }
};
//不会
//动态规划初始条件不会
//不会啊
bool isMatch(string s, string p) {
	char *ss=&s[0],*pp=&p[0];
	char *start=NULL,*rs=NULL;
	while (*ss!='\0'){
		if (*pp=='?'||*ss==*pp){
		    ss++;pp++;continue;
		}
			
		if (*pp=='*'){
			start=++pp;
			rs=ss;continue;
		}
		if (start!=NULL){
			pp=start;
			ss=++rs;continue;
		}
		return false;
	}
	while (*pp=='*'){
		pp++;
	}
	return *pp=='\0';
}
// 做了好多遍了，还是不会啊
