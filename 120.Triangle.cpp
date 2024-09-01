//北大老师称之为地推
//在网上看了好多的版本，其实这就是动态规划，只不过不要从上而下（对于本题）
//动归最好从能够理解的那一层次开始，即从最开始的地方的那一层开始.
//https://leetcode.com/problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
		vector<vector<int>>dp(m,vector<int>(m,0));
		for (int i=0;i<m;i++){
			dp[m-1][i]=triangle[m-1][i];
		}
		for (int i=m-2;i>=0;i--){
			for (int j=0;j<=i;j++){
				dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
			}
		}
		return dp[0][0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
	vector<int>dp(triangle.back());
	
	for (int i=m-2;i>=0;i--){
		for (int j=0;j<=i;j++){
			dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
		}
	}
	return dp[0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1) return triangle[0][0];
        int n=triangle.size();
        vector<vector<int>> dp(triangle);
        for(int i=1; i<triangle.size(); i++){
            // first
            dp[i][0] += dp[i-1][0] ;
            // middle part
            for(int j=1; j<i; j++){
                dp[i][j] += min(dp[i-1][j-1], dp[i-1][j]) ;
            }
            // last
            dp[i][i] += dp[i-1][i-1] ; 
        }
        
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
