class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n,0));  
        int m=n, count=1;

        int left=0, right=n-1, up=0, down=m-1;
        while(left<=right && up <=down){
            for(int i=left; i<=right; i++) matrix[up][i]=count++;
            if(++up > down) break;
            for(int i=up; i<=down; i++) matrix[i][right]=count++;
            if(--right < left) break;
            for(int i=right; i>=left; i--) matrix[down][i]=count++;
            if(--down<up) break;
            for(int i=down;i>=up;i--) matrix[i][left]=count++;
            if(left++>right) break;
        }
        return matrix;
    }
};
//和matrix一样，两题都不会啊
//不会的
