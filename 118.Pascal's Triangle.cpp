class Solution {
public:
    vector<vector<int>> res;
    vector<int> tem;
    vector<vector<int>> generate(int numRows) {
        
    	for (int i=0;i<numRows;i++){
    		tem.insert(tem.begin(),1);
    		if(i>=2){
    		    for (int j=1;j<=tem.size()-2;j++){
        			tem[j]=tem[j]+tem[j+1];//11--111--121--1121-1331
        		}
    		}
    		res.push_back(tem);
    	}
    	return res;
    }
};
//在c++里面要强调if(i>=2)  Java不需要
