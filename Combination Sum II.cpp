class Solution {
public:
    vector<int>tem;
    vector<vector<int>>res;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        combinationHelper(0,candidates,target);
        return res;
    }
    
    void combinationHelper(int start,vector<int>&candidates,int target){
        if(target==0){
            if(find(res.begin(),res.end(),tem)==res.end()){
                res.push_back(tem);
                return;
            }
        }
        if(start>=candidates.size()||target<0)//防止到后面出现较大的数值而一直添加到tem里面去
            return;
        for(int i=start;i<candidates.size();i++){
            tem.push_back(candidates[i]);
            combinationHelper(i+1,candidates,target-candidates[i]);
            tem.pop_back();
        }
    }
};
