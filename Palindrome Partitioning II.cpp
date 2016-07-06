int minCut(string s) {
	int len=s.size();
	vector<int>cut(len,0);//  count[i]=从0到i的最小剪切数
	vector<vector<bool>>dp(len,vector<bool>(len,false));
	for (int i=0;i<len;i++){
		//123
		cut[i]=i;
		for (int j=0;j<=i;j++){
			if ((i-j<2||dp[j+1][i-1]==true)&&s[j]==s[i]){
				dp[j][i]=true;
				cut[i]=j==0?0:min(cut[i],cut[j-1]+1);
			}
		}
	}
	return cut[len-1];
}
// (i-j<2||dp[j+1][i-1]==true)   i-j<2要写在前面的
// 还是不会啊，出现小毛病啦，不会
