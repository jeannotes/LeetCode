class Solution {
public:
    int numDistinct(string s, string t) {
    	int len1=s.size(),len2=t.size();
    	vector<vector<int>>dp(len1+1,vector<int>(len2+1));
    	dp[0][0]=1;//dp[i][j]  s[0...i-1]--t[0..j-1]
    	for (int i=1;i<=len1;i++){
    		dp[i][0]=1;
    	}
    	for (int i=1;i<=len2;i++){
    		dp[0][i]=0;
    	}
    	for (int i=1;i<=len1;i++){
    		for (int j=1;j<=len2;j++){
    			if (s[i-1]==t[j-1]){
    				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    			}else
    				dp[i][j]=dp[i-1][j];
    		}
    	}
    	return dp[len1][len2];
    }
};
// 之前理解有误，单从字面理解，可以想为，s中字符删减多少次变成t中的字符
//但写代码的时候还是不能够按照这种方法来理解，只是由给的列子来看，还是使用删减法来理解最好不过
//还是有问题
