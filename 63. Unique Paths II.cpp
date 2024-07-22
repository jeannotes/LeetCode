class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0)); 
        
        if(obstacleGrid[0][0]==1) return 0;
        dp[0][0] = 1;
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1) continue; 
                if(i) dp[i][j] +=dp[i-1][j] ;
                if(j) dp[i][j]+=dp[i][j-1] ;
            }
        }
        return dp[m-1][n-1];
    }
};

//  竟然会有问题，一开始开头和结尾出现1 就应该干掉
