class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        if(matrix.empty()||matrix[0].empty())
            return res;
        int m=matrix.size(),n=matrix[0].size();
        int left=0,right=n-1;
        int up=0,down=m-1;
        
        while(up<=down&&left<=right){
            for(int i=left;i<right;i++)
                res.push_back(matrix[up][i]);
            for(int i=up;i<=down;i++)
                res.push_back(matrix[i][right]);
            if(up==down||right==left)
                break;
            //这里不能和之前旋转矩阵一样，因为如果出现up=down，需要退出，
            //所以必须i<=down
            //didn't understand
            for(int i=right-1;i>=left;i--)
                res.push_back(matrix[down][i]);
            for(int i=down-1;i>up;i--)
                res.push_back(matrix[i][left]);
            left++;
            right--;
            up++;
            down--;    
        }
        
        return res;
    }
};
//还是不会
