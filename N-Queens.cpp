class Solution {
public://http://bangbingsyb.blogspot.sg/2014/11/leetcode-n-queens-i-ii.html
    vector<int> saveCol;// 存储每一行中的列数字
    vector<vector<string>> res;
    vector<string> tem;
    vector<vector<string>> solveNQueens(int n) {
        solveHelper(n,0);
        return res;
    }
    
    void solveHelper(int n,int row){
        if(row==n){
            res.push_back(tem);return;
        }
        for(int col=0;col<n;col++){
            if(isValid(row,col)){
                string s(n,'.');
                s[col]='Q';
                tem.push_back(s);
                saveCol.push_back(col);
                solveHelper(n,row+1);
                saveCol.pop_back();
                tem.pop_back();
                s[col]='.';
            }
        }
    }
    bool isValid(int row,int col){
        if(row<saveCol.size())
            return false;
        for(int i=0;i<saveCol.size();i++){
            if(saveCol[i]==col||abs(saveCol[i]-col)==abs(row-i))
                return false;
        }
        return true;
    }
};
//不会啊,还是不会啊,还是不会啊，中午做了一下，还可以啊
// 基本可以，小错误啊，今天早上再联系
