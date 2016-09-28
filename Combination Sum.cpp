class Solution {
public:
    vector<int>tem;
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        combinationHelper(0,candidates,target);
        return res;
    }
    void combinationHelper(int start,vector<int>&candidates,int target){
        if(target==0){
            res.push_back(tem);
            return;
        }
        if(start>=candidates.size()||target<0)//防止到后面出现较大的数值而一直添加到tem里面去
            return;
        for(int i=start;i<candidates.size();i++){
            tem.push_back(candidates[i]);
            combinationHelper(i,candidates,target-candidates[i]);
            tem.pop_back();
        }
    }
};
// target<0 的情况没有考虑到
//还有就是c++ 要多考虑引用的问题 挺好的
//还不错，今天状态挺好，待会我再做最前面几题，嘿嘿
// ||target<0 这种情况没有考虑啊 命途多舛啊 
