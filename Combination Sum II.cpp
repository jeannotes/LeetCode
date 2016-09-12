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

class Solution {
public:
    vector<vector<int>>res;
    vector<int>tem;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        combinationHelper(candidates,0,target);
        return res;
    }
    
    void combinationHelper(vector<int>& candidates,int start,int target){
        if(target==0){
            res.push_back(tem);
            return;
        }
        if(target<0)
            return;
        for(int i=start;i<candidates.size();i++){
            if(i>start&&candidates[i]==candidates[i-1])
                continue;
            tem.push_back(candidates[i]);
            combinationHelper(candidates,i+1,target-candidates[i]);
            tem.pop_back();
        }
    }
};
//第二种方法也很容易理解，1 1 1,再加一个和之前相同的数字，抛弃
//一次通过
//target==0) 这个条件要放在前面
//  要及时的存进去，这边如果调换位置，那么[1]1就会返回为空啊       
/*if(target==0){
            res.push_back(tem);
            return;
        }
        if(target<0)
            return;  */ 
//还是在回溯那边，有关位置顺序的地方出错啊，以后记住，谁在前面，先考虑谁啊 还行啊
//  第一种方法更容易理解，其实这个时候还是要练习一下前面那题哦 https://leetcode.com/problems/permutations-ii/
// target<0 这块总是记不住啊
