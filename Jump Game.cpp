class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step=nums[0];
        for(int i=1;i<nums.size();i++){
            if(step>0){
                step=max(--step,nums[i]);
            }else
                return false;
        }
        return true;
    }
};
