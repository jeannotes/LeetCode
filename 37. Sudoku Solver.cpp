class Solution {
public: 
    int rowValid[9][10]={{0}}; 
    int colValid[9][10]={{0}};  
    int subBoard[9][10]={{0}}; 

    bool isValid(int row,int col,int val){
        if(rowValid[row][val] || colValid[col][val] || subBoard[row/3*3+col/3][val]) return false;
        return true;
    }

    void fill(int row, int col , int val){
        rowValid[row][val]=1;
        colValid[col][val]=1;
        int sub=row/3*3+col/3;
        subBoard[sub][val]=1;
    }

    void clear(int row, int col , int val){
        rowValid[row][val]=0;
        colValid[col][val]=0;
        int sub=row/3*3+col/3;
        subBoard[sub][val]=0;
    }

    bool solver(vector<vector<char> > &board, int index){
        if(index>80)    return true;//标准的回溯判断
        int row,col;
        row=index/9;col=index-9*row;
        
        if(board[row][col]!='.'){
            return solver(board,index+1);
        }
 
        for(int i=1; i<=9; i++){
            if (isValid(row, col, i)){
                fill(row, col, i);
                board[row][col]=i+'0';
                if(solver(board, index+1)) return true;
                board[row][col]='.';
                clear(row, col, i);
            }
        }
        return false;
    }
     
    void solveSudoku(vector<vector<char> > &board) {
         for(int i=0; i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.')  fill(i, j, board[i][j]-'0');
                
            }
         }
         solver(board, 0);
    }
    
}; 
//bug-exist  bool solve函数最后的 return false 还是忘记写了
// 还是不会啊,well some kind of good
//还是不会，有太多的小错误了，还是不会啊，每次都要看答案，加油啊，还是蛮不错的
//  if(index>80)    return true;  //标准的回溯判断  我在这边竟然写了return false
