class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step=nums[0];
        for(int i=1;i<nums.size();i++){
            if(step>0){
                step--;
                step=max(step,nums[i]);
            }else
                return false;//step<0 , which mean it cannot jump to the iTH step;
        }
        return true;
    }
};
