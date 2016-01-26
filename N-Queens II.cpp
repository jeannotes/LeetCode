class Solution {
public:
    int count=0;
    int totalNQueens(int n) {
        vector<int>saveCol;
        solveHelper( n,0,saveCol );
        return count;
    }
    
    void solveHelper(int n,int row,vector<int>&saveCol ){
        if(row ==n){
            count++;
            return;
        }
        
        for(int col=0;col<n;col++){
            if(isValid( saveCol,row,col)){
                saveCol.push_back(col);
                solveHelper(n,row+1,saveCol );
                saveCol.pop_back();
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

 
    
 
