class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        if(n==0)
            return matrix;
        int left=0,right=n-1,up=0,down=n-1;
        int count=1;
        while(up<=down&&left<=right){
            for(int i=left;i<right;i++)
                matrix[up][i]=count++;
            for(int i=up;i<=down;i++)
                matrix[i][right]=count++;
            
            if(up==down||right==left)
                break;
            //这里不能和之前旋转矩阵一样，因为如果出现up=down，需要退出，
            //所以必须i<=down
            for(int i=right-1;i>=left;i--)
                matrix[down][i]=count++;
            for(int i=down-1;i>up;i--)
                matrix[i][left]=count++;
            left++;
            right--;
            up++;
            down--;    
        }
        
        return matrix;
    }
};
//和matrix一样，两题都不会啊
