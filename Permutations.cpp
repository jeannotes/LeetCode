class Solution {
public:
//https://leetcode.com/problems/permutations/
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> >result;
        
        permuteHelper(0,nums,result);
        return result;
    }
    
    void permuteHelper(int start,vector<int>& nums,vector<vector<int> >&result){
        if(start==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[i],nums[start]);
            permuteHelper(start+1,nums,result);
            swap(nums[i],nums[start]);
        }
    }
};
