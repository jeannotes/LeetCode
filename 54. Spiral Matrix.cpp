class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size(), n=matrix[0].size();

        int left=0, right=n-1, up=0, down=m-1;
        while(left<=right && up <=down){
            for(int i=left; i<=right; i++) res.push_back(matrix[up][i]);
            if(++up > down) break;
            for(int i=up; i<=down; i++) res.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i=right; i>=left; i--) res.push_back(matrix[down][i]);
            if(--down<up) break;
            for(int i=down;i>=up;i--) res.push_back(matrix[i][left]);
            if(left++>right) break;
        }
        return res;
    }
};
//还是不会
// bug太多啊
// bug还有，不过知道错误在哪儿了
