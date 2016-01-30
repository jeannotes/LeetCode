class Solution {
    //题目的意思是判断当前的数字是否有效
public:
    int rowValid[9][10]={{0}};
    int colValid[9][10]={{0}};
    int subValid[9][10]={{0}};//0代表有效
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<=8;i++){
            for(int j=0;j<=8;j++){
                if(board[i][j]=='.')
                    continue;
                int index=(int)(board[i][j]-'0');
                if( !isValid(i,j,index) )
                    return false;
                 fill(i,j,index);   
            }
        }
        return true;
    }
    
    bool isValid(int row,int col,int val){
        if(colValid[col][val]==0&&rowValid[row][val]==0&&subBoard[row/3*3+col/3][val]==0)
            return true;
        else
            return false;
    }
    
    void fill(int row,int col,int val){
        rowValid[row][val]=1;  
        colValid[col][val]=1;
        subValid[row/3*3+col/3][val]=1; 
    }
};
