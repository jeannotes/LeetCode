class Solution {
public:

    int rowValid[9][10];//判断第i行数字j是否合格
    int colValid[9][10];//判断第i列数字j是否合格
    int subBoard[9][10];//判断第i个小个子（3*3）数字j是否合格

    bool isValid(int row,int col,int val){
        if(rowValid[row][val]==0 && colValid[col][val]==0 && subBoard[row/3*3+col/3][val]==0 )     return true;
        return false;
    }
    
    void fill(int row,int col,int val){//更新状态
        rowValid[row][val]=1;
        colValid[col][val]=1;
        subBoard[row/3*3+col/3][val]=1;
    }
    
    void clear(int row,int col,int val){//清除原来状态
        rowValid[row][val]=0;
        colValid[col][val]=0;
        subBoard[row/3*3+col/3][val]=0;
    }

    bool solver(vector<vector<char> > &board,int index){//index表示第几个小个子
        // 0<=index<<80
        if(index>80)    return true;//标准的回溯判断
        int row,col;
        row=index/9;col=index-9*row;
        
        if(board[row][col]!='.'){
            return solver(board,index+1);
        }
        
        for(int i=1;i<=9;i++){
            if(isValid( row, col, i) ){
                board[row][col]=i+'0';
                fill( row, col,i );
                if(solver( board, index+1))     return true;
                clear( row, col,i );
                board[row][col]='.';//标准的回溯格式
            }    
        }
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        //首先更新3个数组
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.') 
                    fill( i,j,board[i][j]-'0' );
            }
        }
        solver(board,0);
    }
    
};
