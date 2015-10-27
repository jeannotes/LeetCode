class Solution1 {
public:
//在之前有一个题目使用自下而上的解法
//http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-i.html
//这只是第一种想法，还有一种待会写。
    string longestPalindrome(string s){
        int n=s.length();
        int longestBegin=0;
        int maxLen=1;
        bool table[1000][1000]={false};//  s[i....j]
        
        for(int i=0;i<n;i++){
            table[i][i]=true;//单个字符绝对可以成为回文串
            longestBegin=i;
            maxLen=1;
        }
        
        //table的初始化
        for(int i=0;i<=n-2;i++){
            if(s[i]==s[i+1]){//看有没有相隔2个字符可以成为回文串的
                table[i][i+1]=true;
                longestBegin=i;
                maxLen=2;
            }
        }
        //接下来查看间隔是3的情形
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=len+i-1;
                if(s[i]==s[j]&&table[i+1][j-1]){
                    table[i][j]=true;
                    longestBegin=i;
                    maxLen=len;
                }
            }
        }
        
        return s.substr(longestBegin,maxLen);
    }

};


class Solution2 {
public:
//第二种写法，从中心拓展
    string longestPalindrome(string s){
        int n=s.length();
        if(n==0){
            return "";
        }
        string longest=s.substr(0,1);
        
        for(int i=0;i<n;i++){
            string p1=expandAroundCenter( s,i,i);//围绕中心i使劲往两边走
            if(p1.length()>=longest.length()){
                longest=p1;
            }
            string p2=expandAroundCenter( s,i,i+1);//围绕中心i使劲往两边走
            if(p2.length()>=longest.length()){
                longest=p2;
            }
        }
        return longest;
    } 
    string expandAroundCenter(string &s,int c1,int c2){
        int len=s.length();
        while(c1>=0&&c2<=len-1&&s[c1]==s[c2]){
            c1--;c2++;
        }
        return s.substr(c1+1,c2-c1-1);//第一个参数是起始位置，第二个是长度，闭区间
    }
};
