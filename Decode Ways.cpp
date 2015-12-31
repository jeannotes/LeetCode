class Solution {
public:
    int numDecodings(string s) {
        //dp[i]  --  s[0..i-1]
        if(s.empty())   
            return 0;
        int len=s.length();
        int sum[len+1];
        
        sum[0]=1;
        sum[1]=s[0]=='0'?0:1;
        
        for(int i=2;i<=len;i++){
            if(s[i-1]=='0') sum[i]=0;
            else    sum[i]=sum[i-1];
            
            if( s[i-2]=='1'|| (s[i-2]=='2'&&s[i-1]<='6') )
                sum[i]+=sum[i-2];
        }
        return sum[len];
    }
};
