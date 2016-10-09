class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if (nums.empty())
    		return 0;
    	int len = nums.size();
    
    	vector<int>dp(len, 1);
    
    	for (int i = 0; i < len;i++) {
    		for (int j = 0; j < i;j++) {
    			if (nums[j] < nums[i] )//12345
    				dp[i] = max(dp[i], dp[j] + 1);
    		}
    	}
    	int res = INT_MIN;
    	for (int i = 0; i < len;i++) {
    		res = max(res, dp[i]);
    	}
    	return res;
    }
};
