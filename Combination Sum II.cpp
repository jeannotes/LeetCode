class Solution {
public:
//https://leetcode.com/problems/combination-sum-ii/
        vector<int>temp;
        vector<vector<int> >result;
        
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        sumHelper(candidates,target,0,candidates.size());
        return result;
    }
    
    void sumHelper(vector<int>& candidates,int target,int index,int length){
        //index代表数组索引值，length代表数组长度
        if(target==0){
            //这里很巧的是，别人用sum求和，他不用，他是相减，只要等于0了，就会存入数组中。
            if(find(result.begin(),result.end(),temp)==result.end()){   
                result.push_back(temp);
            }
            return;//不需要返回
        }
        if(index>=length||target<0){//因为是求减法，如果不相等，立即返回||
                                   //还有一种是索引值大于数组长度
            return;
        }
        /*
        if (target < candidates[start]) {
            return;
        }  It seems it is also ok   
        */
        
        for(int i=index;i<=length-1;i++){
            temp.push_back(candidates[i]);
            sumHelper(candidates,target-candidates[i],i+1,length);
            temp.pop_back();
        }
    }
};
