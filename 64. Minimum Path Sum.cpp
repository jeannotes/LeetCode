class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty()) return 0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {dp[i][j]=grid[i][j];continue;}
                if(i) dp[i][j]=min(dp[i][j],dp[i-1][j]+grid[i][j]);
                if(j) dp[i][j]=min(dp[i][j],dp[i][j-1]+grid[i][j]);
            }
        }
        return dp[m-1][n-1];
    }
};
//bug-free
