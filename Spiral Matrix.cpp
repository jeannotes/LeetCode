class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        
        if(matrix.empty() || matrix[0].empty()){
            return res;
        }
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0,right=n-1;
        int up=0,down=m-1;
        
        while(up<=down&&left<=right){
            for(int i=left;i<=right;i++){
                res.push_back(matrix[up][i]);
            }
            
            for(int i=up+1;i<=down;i++){
                res.push_back(matrix[i][right]);
            }
            
            if(up==down||left==right){    
                break;
            }
                for(int i=right-1;i>=left;i--){
                    res.push_back(matrix[down][i]);
                }
            
                for(int i=down-1;i>=up+1;i--){
                    res.push_back(matrix[i][left]);
                }
            up++;
            right--;
            down--;
            left++;
        }
        
        return res;
    }
};
