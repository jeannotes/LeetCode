class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n==0)    {
            res.push_back(0);return res;
        }
        res.push_back(0);
        res.push_back(1);
        if(n==1)    return res;
        
        // 0,1--0,1,2,3--0,1,2,3,4,,5,6,7
        for(int i=2;i<=n;i++){
            int high=pow(2,i-1);
            vector<int> tmp;
            for(int j=res.size()-1;j>=0;j--){
                tmp.push_back(high+res[j]);
            }
            for(int j=0;j<tmp.size();j++){
                res.push_back(tmp[j]);
            }
            //res.push_back(tmp);
        }
        
        return res;
    }
    
    
};
