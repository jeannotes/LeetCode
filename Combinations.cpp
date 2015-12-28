class Solution {
public:
    vector<vector<int>>res;
    vector<int>tem;
    vector<vector<int>> combine(int n, int k) {
        combineHelper(1,n,k);
        return res;
    }
    
    void combineHelper(int start,int n,int k){
        if(tem.size()==k){
            res.push_back(tem);
            return;
        }
        
        for(int i=start;i<=n;i++){
            tem.push_back(i);
            combineHelper(i+1,n,k);
            tem.pop_back();
        }
    }
};
