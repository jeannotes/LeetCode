class Solution {
    //http://bangbingsyb.blogspot.sg/2014/11/leetcode-n-queens-i-ii.html
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>tem;
        vector<int>saveCol;// 存储每一行中的列数字
        solveHelper(n,0,saveCol,tem,res);
        return res;
    }
    
    void solveHelper(int n,int row,vector<int>&saveCol,vector<string> &tem,vector<vector<string>>&res){
        if(row ==n){
            res.push_back(tem);
            return;
        }
        
        for(int col=0;col<n;col++){
            if(isValid( saveCol,row,col)){
                string s(n,'.');
                saveCol.push_back(col);
                s[col]='Q';
                tem.push_back(s);
                solveHelper(n,row+1,saveCol,tem,res);
                s[col]='.';
                saveCol.pop_back();
                tem.pop_back();
            }
        }
    }
    
    bool isValid(vector<int>&saveCol,int row,int col){
        if(row<saveCol.size())
            return false;
        for(int i=0;i<saveCol.size();i++){
            if(col==saveCol[i]||abs(i-row)==abs(col-saveCol[i]))
                return false;
        }
        return true;
    }
};
