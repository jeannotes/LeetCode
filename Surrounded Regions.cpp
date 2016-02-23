class Solution {
public:
    void solve(vector<vector<char>>& board){
		if (board.empty()||board[0].empty()){
			return;
		}
		int m=board.size(),n=board[0].size();
		for (int i=0;i<m;i++){
			if (board[i][0]=='O'){
				walk(board,i,0);
			}
			if (board[i][n-1]=='O'){
				walk(board,i,n-1);
			}
		}

		for (int i=0;i<n;i++){
			if (board[0][i]=='O'){
				walk(board,0,i);
			}
			if (board[m-1][i]=='O'){
				walk(board,m-1,i);
			}
		}

		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				if (board[i][j]=='#'){
					board[i][j]='O';
				}else
					board[i][j]='X';
			}
		}
	}

	void walk(vector<vector<char>>& board,int i,int j){
		int m=board.size(),n=board[0].size();
		queue<pair<int,int>>q;
		q.push(make_pair(i,j));

		while (!q.empty()){
			pair<int,int> tem=q.front();
			q.pop();
			int k=tem.first,l=tem.second;
			if (0<=k&&k<m&&0<=l&&l<=n-1&&board[k][l]=='O'){
				board[k][l]='#';
				q.push(make_pair(k-1,l));q.push(make_pair(k+1,l));
				q.push(make_pair(k,l-1));q.push(make_pair(k,l+1));
			}
		}
	}
};
//深度优先会出错，使用广度优先
//walk 函数还不会
