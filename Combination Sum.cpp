class Solution {
public:
//
        vector<int>temp;
        vector<vector<int> >result;
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        sumHelper(candidates,target,0,candidates.size());
        return result;
    }
    
    void sumHelper(vector<int>& candidates,int target,int index,int length){
        //index代表数组索引值，length代表数组长度
        if(target==0){
            //这里很巧的是，别人用sum求和，他不用，他是相减，只要等于0了，就会存入数组中。
            result.push_back(temp);
            return;//不需要返回
        }
        if(index>=length||target<0){//因为是求减法，如果不相等，立即返回||
                                   //还有一种是索引值大于数组长度
            return;
        }
        
        for(int i=index;i<=length-1;i++){
            temp.push_back(candidates[i]);
            sumHelper(candidates,target-candidates[i],i,length);
            temp.pop_back();
        }
    }
};
