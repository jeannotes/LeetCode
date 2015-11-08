class Solution {
//https://leetcode.com/problems/valid-sudoku/
public:
//虽说题目要用hash，尽管我程序里面没有定义hash,反而定义的是数组，所以，本质上也是hash。   
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowValid[9][10] ={false};
        bool colValid[9][10] ={false};
        bool subBoard[9][10] ={false};
    
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')    continue;
                /**/
                int index=board[i][j]-'0';
                /*
                if(rowValid[i][index])  return false;
                   
                if(colValid[j][index])   return false;
                   
                if(subBoard[(i/3)*3+j/3][index])    return false;*/
                if((rowValid[i][index])||(colValid[j][index])||(subBoard[i/3*3+j/3][index]) )   
                    return false;   
                rowValid[i][index]=true;
                colValid[j][index]=true;
                subBoard[i/3*3+j/3][index]=true;
            }
        }
        
        return true;
    }

};
