class Solution {
public:
//https://leetcode.com/problems/unique-paths-ii/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        int sum[m][n];
        sum[0][0]=1;
        for(int i=1;i<n;i++){
            sum[0][i]=obstacleGrid[0][i]==0?sum[0][i-1]:0;
        }//如果等于1，直接为0；如果不为1，和前面相同
        for(int i=1;i<m;i++){
            sum[i][0]=obstacleGrid[i][0]==0?sum[i-1][0]:0;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                sum[i][j] = obstacleGrid[i][j]==0?(sum[i-1][j]+sum[i][j-1]):0;
            }
        }
        
        return sum[m-1][n-1];
    }
};
//基本没问题，没能够bug-free
