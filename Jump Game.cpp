class Solution {
//https://leetcode.com/problems/jump-game/
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
            return false;
        int step=nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(step>0){
                step--;
                step=max(step,nums[i]);
            }else
                return false;
        }
        return true;
    }
};
