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
class Solution3 {
public:
    vector<int> tem;
    vector<int> getRow(int rowIndex) {
        for (int i=0;i<=rowIndex;i++){
    		tem.insert(tem.begin(),1);
    		if(i>=2){
    		    for (int j=1;j<=tem.size()-2;j++){
        			tem[j]=tem[j]+tem[j+1];//11--111--121--1121-1331
        		}
    		}
    	}
    	return tem;
    }
};
//果真网上大神很多
