class Solution {
public:
    vector<int> saveCol;// 存储每一行中的列数字
    int count=0;
    int totalNQueens(int n) {
        solveHelper(n,0);
        return count;
    }
    
    void solveHelper(int n,int row){
        if(row==n){
            count++;
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(row,col)){
                saveCol.push_back(col);
                solveHelper(n,row+1);
                saveCol.pop_back();
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
//这个算是比较难得回溯啦，加油啊
//  还是不会啊
