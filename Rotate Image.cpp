class Solution {
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
