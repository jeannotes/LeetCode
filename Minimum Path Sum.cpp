class Solution {
public:
//https://leetcode.com/problems/minimum-path-sum/
    int minPathSum(vector<vector<int> >& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==0||n==0){
            return 0;
        }
//        int sum[m][n];
        for(int j=1;j<n;j++){
            grid[0][j]=grid[0][j-1]+grid[0][j];
        }
        
        for(int i=1;i<m;i++){
            grid[i][0]=grid[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j];
            }
        }
        
        return grid[m-1][n-1];
    }
};
