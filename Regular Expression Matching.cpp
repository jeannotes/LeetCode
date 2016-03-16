class Solution {
public:
//https://leetcode.com/problems/regular-expression-matching/
//记住 本题与wildcard matching不同的
    bool isMatch1(string s, string p) {
        //if (s.empty()) return p.empty();  不需要判断s是否为空，因为后面万一出现A*之类的，反正A可以算0次
        //但是当p是空的时候，s一定要是空的
        if (p.empty()) return s.empty();
        if(p[1]!='*'){
            if(p[0]==s[0]||(p[0]=='.'&&s[0]!='\0')){
                //s不能结尾
                return isMatch(s.substr(1), p.substr(1));
            }else 
                return false;
        }else{
            if (isMatch(s, p.substr(2)))  return true;////代表前面的字符出现0次   而且还算是迭代，方便后面继续出现***
            int index=0;
            while(index<s.size()&&(s[index]==p[0]||p[0]=='.')){
                if(isMatch(s.substr(++index), p.substr(2)))   return true;
            }//这个时候先是让前面的一个字符出现一次,再是2次....
            return false;
        }
    }
    
//动态规划，切记所谓的之前字符就是* 之前的那个字符    
    bool isMatch2(string s, string p){
        /*
        f[i][j]==ifs[0...i-1] p[0...j-1]
        */
        int m=s.size(),n=p.size();
        
        vector<vector<bool> > f(m+1,vector<bool>(n+1,false));
        //初始化 initialize
        f[0][0]=true;
        for(int i=1;i<=m;i++){
            f[i][0]=false;
        }
        for(int i=1;i<=n;i++){
            f[0][i]=i>1&&p[i-1]=='*'&&f[0][i-2];//因为此时是空的
        }
  	//这里其实
	// p[0.., j - 3, j - 2, j - 1] matches empty
	//if p[j - 1] is '*' and p[0..j - 3] matches empty
	//假设p[0]=* 这时候f[0][0]=true  不影响的
	    for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]!='*'){
                    f[i][j]=f[i-1][j-1]&&(p[j-1]==s[i-1]||p[j-1]=='.');
                }else{
                    //p[0] 不能还*
                    f[i][j]=f[i][j-2]||(    f[i-1][j]&&(p[j-2]==s[i-1]||p[j-2]=='.' )  );
                    // f[i][j]=f[i][j-2]|| f[i-1][j-2]&&p[j-2]==s[i-1]  || f[i-2][j-2]&&p[j-2]==s[i-1]&&p[j-2]==s[i-2] ...
                    //           f[i-1][j]=f[i-1][j-2]|| f[i-2][j-2]&&p[j-2]==s[i-2] || ....
                    //f[i][j] = f[i][j - 2] || ((s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j]);
                }
            }
        } 
        return f[m][n];
    }
};
//还是不会
// 第一种方法还有问题，第二种没问题
