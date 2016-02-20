class Solution {
public:
//https://leetcode.com/problems/palindrome-partitioning-ii/
    int minCut(string s) {
        //核心公式
        //  count[i]=从i到尾的最小剪切数
        //  count[i]=min{  count[j+1]+1  }  +  dp[i][j]==1   j=i....s.length()        
        int len = s.size();  
        int count[len+1];
        bool dp[len][len];     
            
        for(int i = 0; i <= len; i++){
            count[i] = len-i; //这个地方，按照最右边来算，
                              //假设是“abcd” count[5]=0,count[4]=1,count[3]=2...count[0]=5,其实只需要4次即可    
        }   
                 
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                dp[i][j] = false;     
            }   
        }  


        for(int i=len-1;i>=0;i--){
            
            for(int j=i;j<=len-1;j++){
                if((j-i<2||dp[i+1][j-1]==1)&& s[i]==s[j]){
                    dp[i][j]=true;
                    count[i]=min(   count[i],count[j+1]+1    );
                }
            }
        }
        
        return count[0]-1;
    }
};
