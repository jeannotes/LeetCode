class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0; i<m; i++){
            if(board[i][0]=='O') walk(board, i, 0);
            if(board[i][n-1]=='O') walk(board, i, n-1);
        }
        for(int i=1; i<n-1; i++){
            if(board[0][i]=='O') walk(board, 0, i);
            if(board[m-1][i]=='O') walk(board, m-1, i);
        }
        for(int i=0;i<m; i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }

    void walk(vector<vector<char>>& board, int i, int j) {
        int m=board.size(), n=board[0].size();
        if(i<0 || i>=m || j<0 || j>=n) return;
        if(board[i][j] != 'O') return;

        queue<std::pair<int, int>> q;
        q.push(std::make_pair(i,j));

        while(!q.empty()){
            std::pair<int, int> t = q.front();q.pop();
            int k=t.first, l=t.second;
            if(0<=k && k<m && 0<=l && l<n && board[k][l]=='O'){
                board[k][l]='#';
                q.push(std::make_pair(k-1,l));q.push(std::make_pair(k,l-1));
                q.push(std::make_pair(k+1,l));q.push(std::make_pair(k,l+1));
            } 
        } 
    }
};
//深度优先会出错，还不会啊，会那么一丢丢了
//   再次犯了把q.push(make_pair(k-1,l));  里面写成i，j了的错误，还是不会了啊，还是不会啊
