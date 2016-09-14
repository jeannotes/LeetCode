class Solution {
//https://leetcode.com/problems/word-search/
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())   return false;
        if(word.empty())    return false;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(existHelper(board,word,i,j,0))   return true;
            }
        }
        return false;
    }
    
    bool existHelper(vector<vector<char> >&board,string word,int i,int j,int k){
        if(k==word.size())  return true;//k代表的是第几位
        
        if(i<0||i>=board.size()||j<0||j>=board[0].size())   return false;
        if(board[i][j]!=word[k])    return false;
        
        board[i][j]='#';//防止以后再次返回到当前节点。直接设置一个非字符
        
        bool result=(existHelper(board,word,i-1,j,k+1) || existHelper(board,word,i+1,j,k+1)
                    ||existHelper(board,word,i,j-1,k+1) || existHelper(board,word,i,j+1,k+1));
        board[i][j]=word[k];
        
        return result;
    }
};
//可以啊，基本一次通过，下去买包子
// 还可以啊，还是不会了啊
bool exist(vector<vector<char> > &board, string word) {
        if(board.empty() || board[0].empty()) return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(findWord(board, visited, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    
    bool findWord(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, string &word, int index) {
        if(index==word.size()) return true;
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || visited[row][col] || board[row][col]!=word[index]) 
            return false;
            
        visited[row][col] = true;
        if(findWord(board, visited, row-1, col, word, index+1)) return true;  
        if(findWord(board, visited, row+1, col, word, index+1)) return true;
        if(findWord(board, visited, row, col-1, word, index+1)) return true;
        if(findWord(board, visited, row, col+1, word, index+1)) return true;
        visited[row][col] = false;
        return false;
    }//号代码啊 haixing ganjue 
