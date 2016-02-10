class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        //      四个位置  i,j....j,n-1-i....,n-1-i,n-j-1....n-j-1,i
        int n= matrix.size();
        for(int i=0;i<=(n-1)/2;i++){
            for(int j=i;j<n-1-i;j++){
                swap4p( matrix,i,j,n-1-i,n-j-1);
            }
        }
    }
    
    void swap4p(vector<vector<int>>& matrix,int a,int b,int c,int d){
        //程序的核心在于找到 四个位置 
            swap(matrix[a][b],matrix[b][c]);
            swap(matrix[a][b],matrix[c][d]);
            swap(matrix[a][b],matrix[d][a]);
    }
};

class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int count=m/2;
        for(int i=0;i<=count;i++){
            
            for(int j=i;j<=m-2-i;j++){
                swap(matrix[i][j],matrix[j][m-1-i]);
            }
            for(int j=i;j<=m-2-i;j++){
                swap(matrix[m-1-i][m-1-j],matrix[i][j]);
            }
            for(int j=i;j<=m-2-i;j++){
                swap(matrix[m-1-j][i],matrix[i][j]);
            }
        }
        
    }
};
// 基本一次通过，还有一些小瑕疵
