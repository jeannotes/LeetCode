class Solution {
public:
/*
    void solve(vector<vector<char>>& board) {
        if(board.empty()||board[0].empty()) return;
        int i=0,j=0;
        int m=board.size(),n=board[0].size();
        
        for(;j<n-1;j++){ 
            walk(board,i,j);
        }
        
        for(;i<m-1;i++){        //right
            walk(board,i,j);
        }
        
        for(;j>0;j--){          //down
            walk(board,i,j);
        }
        
        for(;i>0;i--){//left
            walk(board,i,j);
        }
        
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(board[i][j]=='#') board[i][j]='O';
                else    board[i][j]='X';
            }
        }
    }
    
    void walk(vector<vector<char> >&board,int i,int j){
        //DFS
        if(i<0||i>=board.size()||j<0||j>=board[0].size())   return;
        if(board[i][j]=='O'){
            board[i][j]='#';
            walk(board,i-1,j);
            walk(board,i+1,j);
            walk(board,i,j-1);
            walk(board,i,j+1);
        }
    }*/
    
        void bfs(int i, int j, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            if (top.first >= 0 && top.first < n && top.second >= 0 && top.second < m && board[top.first][top.second] == 'O') {
                //如果没有这句话，那么你接下来的make_pair就会出错，溢出.
                board[top.first][top.second] = '#';
                q.push(make_pair(top.first - 1, top.second));
                q.push(make_pair(top.first + 1, top.second));
                q.push(make_pair(top.first, top.second + 1));
                q.push(make_pair(top.first, top.second - 1));
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty()||board[0].empty()) return;
        int m=board.size(),n=board[0].size();
        
        for(int i=0;i<m;i++){
            //最左边与最右边
            if(board[i][0]=='O')    walk( board,i,0);
            if(board[i][n-1]=='O')  walk( board,i,n-1);
        }
        
        for(int i=1;i<n-1;i++){
            //最上边与最下边
            if(board[0][i]=='O')    walk( board,0,i);
            if(board[m-1][i]=='O')  walk( board,m-1,i);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#')    board[i][j]='O';
                else    board[i][j]='X';
            }
        }
    }
    
    void walk(vector<vector<char>>& board,int i,int j){
        int m=board.size(),n=board[0].size();
        queue<pair<int,int>>q;
        q.push(make_pair(i,j));
        while(!q.empty()){
            auto tem=q.front();
            q.pop();
            if(tem.first>=0&&tem.first<m&&tem.second>=0&&tem.second<=n&&board[tem.first][tem.second]=='O'){
                board[tem.first][tem.second]='#';
                q.push(make_pair(tem.first-1,tem.second));
                q.push(make_pair(tem.first+1,tem.second));
                q.push(make_pair(tem.first,tem.second-1));
                q.push(make_pair(tem.first,tem.second+1));
            }
        }
    }
};
