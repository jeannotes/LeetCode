class Solution {
public:
    vector<vector<int>>res;
    vector<int>tem;
    vector<vector<int>> combine(int n, int k) {
        combineHelper(1,n,k);
        return res;
    }
    
    void combineHelper(int start,int n,int k){
        /*
        if(start>n-k+1){//这一段不能要，因为会使得后面的 13 14 15全部消失。n=4，k=2的情况
            return;
        }*/
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
