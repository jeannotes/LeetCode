class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=m*n-1;
        while(i<=j){
            int mid=(i+j)/2;
            int row=(mid/n),col=mid%n;
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]<target)
                i=mid+1;
            if(matrix[row][col]>target)
                j=mid-1;
        }
        return false;
    }
};
//  int row=(mid/n),col=mid%n;  在这个地方出错
//没有问题
