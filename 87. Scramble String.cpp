class Solution {
    //http://www.cnblogs.com/easonliu/p/3696135.html
public:
    class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2) return true;
        if(s1.size()!=s2.size()) return false;
        string ss1=s1,ss2=s2;
        sort(ss1.begin(),ss1.end());
        sort(ss2.begin(),ss2.end());
        if(ss1!=ss2) return false;
        int len = s1.size();
        for(int i=1; i<len;i++){
            string s1_l = s1.substr(0,i),s1_r=s1.substr(i);
            string s2_l = s2.substr(0,i), s2_r = s2.substr(i);
            if(isScramble(s1_l, s2_l)&&isScramble(s1_r, s2_r)) return true;
            string s2_e_l = s2.substr(0,len-i), s2_e_r = s2.substr(len-i,i);
            if(isScramble(s1_l, s2_e_r)&&isScramble(s1_r, s2_e_l)) return true;
        }
        return false;
    }
};
    
    bool isScramble2(string s1, string s2){
        //dp[k][i][j]  -->   s1[i..i+k-1]与s2[i..i+k-1] 
        //initialization 
        //dp[1][i][j]  -->   (s1[i]==s2[j])?true:false
        
        //dp[k][i][j] = dp[divk][i][j]&&dp[k-divk][i+divk][j+divk]
        //      ||      dp[divk][i][j+k-divk]&&dp[k-divk][i+divk][j]
        //牢牢谨记  指的是从i到j个k个字符，既然可以从前面divk个分，也能从后面divk分开
        //他仅仅是从i开始k个字符是否能够匹配，只管这么多。
        //这是动态规划解法
        if(s1.size()!=s2.size()||s1.size()==0||s2.size()==0)
            return false;
        if(s1==s2)
            return true;
        
        const int len=s1.size();
        
        vector< vector<vector<bool> > >dp(len+1,vector<vector<bool> >(len,vector<bool >(len)));
        
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                dp[1][i][j]=(s1[i]==s2[j]);
            }
        }
        
        for(int k=2;k<=len;k++){
            for(int i=0;i<=len-k;i++){
                for(int j=0;j<=len-k;j++){
                    dp[k][i][j]=false;
                    for(int divk=1;divk<k&&dp[k][i][j]==false;divk++){
                        dp[k][i][j]=(dp[divk][i][j]&&dp[k-divk][i+divk][j+divk])||
                                    (dp[divk][i][j+k-divk]&&dp[k-divk][i+divk][j]);
                    }
                }
            }
        }
        
        return dp[len][0][0];
    }
};
// 在第二个if ---  isScramble(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i))    )
//非常容易出错
//动态规划的不会啊
// 为什么动态规划定义的时候不是定义 (len+1,vector<vector<bool>>(len+1,vector<bool>(len+1,false)));
//  因为 //dp[k][i][j] s1[0..i+k-1]-s2[0..j+k-1] k已经等于1，不会有问题的
//  这次递归没能够一次AC，估计时间长了，晚上又做了一遍，还是要在字符串相等的时候就确定
/*
        if(s1==s2)
            return true;  这边没有考虑到啊
            动态规划暂时不做了 太难啊
*/
