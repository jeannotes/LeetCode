class Solution {
public:
//https://leetcode.com/problems/word-break/
//http://blog.csdn.net/feliciafay/article/details/18999903
    bool wordBreak(string s, unordered_set<string>& wordDict) {
		int len=s.size();
		vector<bool>dp(len+1,false);
		dp[0]=true;//dp[i]--s[0..i-1]可以表示
		for (int i=1;i<=len;i++){
			for (int j=0;j<=i-1;j++){
				string tmp=s.substr(j,i-j);
				if (dp[j]&&wordDict.count(tmp)!=0){
					dp[i]=true;break;//这里最好加上这一句，因为到后面万一在j处分开的时候，突然false呢，所以既然true，直接退出
				}
			}
		}
		return dp[len];
	}
};
// string tmp=s.substr(j,i-j);  这个地方是不需要i-j+1的，因为i本身就多1的。
//dp[i]--s[0..i-1] 
//不会做，好题目，但是自己在分析i 和 j的时候分析对了

//我一次做出啊
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    	if (s.empty()){
    		return false;
    	}
    	int len=s.size();
    	vector<bool>dp(len+1,false);//0 1234 
    	dp[0]=true;//dp[i]--s[0..i-1]
    	for (int i=1;i<=len;i++){
    		for (int j=0;j<i;j++){
    			string tmp=s.substr(j,i-j);
    			if (wordDict.find(tmp)!=wordDict.end()&&(j==0||dp[j]==true)){
    				dp[i]=true;
    			}
    		}
    	}
    	return dp[len];
    }


//从前面的回文串的例子总结的方法
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    	int len=s.size();
    	vector<bool>dp(len,false);//dp[i]--s[0...i-1]
    	for (int i=0;i<len;i++){
    		for (int j=0;j<=i;j++){
    			string tem=s.substr(j,i-j+1);
    			if ((j==0||dp[j-1]==true)&&wordDict.find(tem)!=wordDict.end()){
    				dp[i]=true;break;
    			}
    		}
    	}
    	return dp[len-1];
    }
};
//建议使用这个
