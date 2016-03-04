class Solution {
public:
//https://leetcode.com/problems/set-matrix-zeroes/
//每一行每一列投射到最左边最右边，以此作为标志
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())  return;
        bool firRow=false,firCol=false;
        int m=matrix.size(),n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                firCol=true;
                break;
            }
        }
        
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0){
                firRow=true;
                break;
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        if(firCol){
            for(int i=0;i<m;i++)
                matrix[i][0]=0;
        }
        
        if(firRow){
            for(int i=0;i<n;i++)
                matrix[0][i]=0;
        }
    }
};
//不会的，没有写出来
//粗心
