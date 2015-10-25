class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > matrix(n,vector<int>(n,0));
        //vector<vector<bool> >dp(m+1,vector<bool>(n+1,false));
        //int matrix[n][n];
        vector<vector<int>> result;
        if(n==0){
            return result;
        }
        
        int left=0,right=n-1;
        int up=0,down=n-1;
        int count=0;
        
        while(up<=down&&left<=right){
            for(int i=left;i<=right;i++){
                matrix[up][i]=++count;
                //res.push_back(matrix[up][i]);
                //matrix[up].push_back(++count);
            }
            
            for(int i=up+1;i<=down;i++){
                matrix[i][right]=++count;
                //res.push_back(matrix[i][right]);
            }
            
            if(up==down||left==right){    
                break;
            }
            
            for(int i=right-1;i>=left;i--){
                matrix[down][i]=++count;
                //res.push_back(matrix[down][i]);
            }
            
            for(int i=down-1;i>=up+1;i--){
                matrix[i][left]=++count;
                //res.push_back(matrix[i][left]);
            }
            up++;
            right--;
            down--;
            left++;
        }
        
        return matrix;
        
    }
};
