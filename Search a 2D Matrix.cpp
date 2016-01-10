class Solution {
    //https://leetcode.com/problems/search-a-2d-matrix/
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())
            return false;
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=m*n-1;
        
        while(i<=j){
            int mid=(i+j)/2;
            int row=(mid/n),col=mid%n;
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]>target)
                j--;
            if(matrix[row][col]<target)
                i++;
        }
        return false;
    }
};
