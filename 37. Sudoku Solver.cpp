class Solution {
public:
//本题是在board上编辑，所以不需要进行使用void
    int rowValid[9][10];//判断第i行数字j是否合格
    int colValid[9][10];//判断第i列数字j是否合格
    int subBoard[9][10];//判断第i个小个子（3*3）数字j是否合格

    bool isValid(int row,int col,int val){
        if(colValid[col][val]==0&&rowValid[row][val]==0&&subBoard[row/3*3+col/3][val]==0)
            return true;
        else
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
//bug-exist  bool solve函数最后的 return false 还是忘记写了
// 还是不会啊,well some kind of good
//还是不会，有太多的小错误了，还是不会啊，每次都要看答案，加油啊，还是蛮不错的
//  if(index>80)    return true;  //标准的回溯判断  我在这边竟然写了return false
