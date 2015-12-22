class Solution1 {
private:
//https://leetcode.com/problems/n-queens/
    int colFlag;//代表列
    int diagFlag1;//index=i+j
    int diagFlag2;//index=n-1+i-j
    
    bool isValid(int rowIndex,int colIndex,int n){
        //行不需要判断，因为我是按照行走的
        //为0说明有效
        if( (1<<colIndex)&colFlag ){
            //为1 无效
            return false;
        }
        if( (1<<(rowIndex+colIndex))&diagFlag1  ){
            return false;
        }
        if( (1<<(n-1+rowIndex-colIndex) ) & diagFlag2 ){
            return false;
        }
        return true;
    }
    
    void setFlag(int rowIndex,int colIndex,int n){
        colFlag   |=(1<<colIndex);
        diagFlag1 |=(1<<(rowIndex+colIndex));
        diagFlag2 |=(1<<(n-1+rowIndex-colIndex));
    }
    
    
    void unsetFlag(int rowIndex, int colIndex, int n) {
        colFlag &= ~(1 << colIndex);
        diagFlag1 &= ~(1 << (rowIndex + colIndex));
        diagFlag2 &= ~(1 << (n + rowIndex - colIndex - 1));
    }
    
    void queenHelper(int n, vector<string> &answer, vector<vector<string> > &result) {
        int rowIndex = answer.size();

        if (rowIndex == n) {
            result.push_back(answer);
            return;
        }
        
        answer.push_back(string(n, '.'));
        for (int i = 0; i < n; i++) {
            if (isValid(rowIndex, i, n)) {
                setFlag(rowIndex, i, n);
                answer.back()[i] = 'Q';
                queenHelper(n, answer, result);
                answer.back()[i] = '.';
                unsetFlag(rowIndex, i, n);
            }
        }
        answer.pop_back();
    }

public:
    vector<vector<string> > solveNQueens(int n) {
        // https://oj.leetcode.com/problems/n-queens/

        colFlag = diagFlag1 = diagFlag2 = 0;
        vector<vector<string> > result;
        vector<string> answer;

        queenHelper(n, answer, result);
        return result;
    }
};


class Solution2 {
    //http://bangbingsyb.blogspot.sg/2014/11/leetcode-n-queens-i-ii.html
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>tem;
        vector<int>saveCol;
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
