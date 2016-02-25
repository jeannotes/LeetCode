class Solution1 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(1,1);
        if(rowIndex==0){
            return result;
        }
        
        for(int i=1;i<=rowIndex;i++){
            vector<int>temp=result;
            for(int j=1;j<=i-1;j++){
                result[j]=temp[j]+temp[j-1];
            }
            result.push_back(1);
            temp.clear();
        }
        return result;
    }
};

class Solution2 {
//此版本更加简洁
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,1);
        if(rowIndex<=1){
            return result;
        }
        
        for(int i=2;i<=rowIndex;i++){
            for(int j=i-1;j>=1;j--){
                result[j]=result[j]+result[j-1];
            }
        }
        return result;
    }
};
//罗辑思维题目，没有问题
