class Solution {
//https://leetcode.com/problems/jump-game/
public:
    bool canJump(vector<int>& nums) {
        
        int step=nums[0];
        
        if(nums.empty()){
            return false;
        }
        for(int i=1;i<nums.size();i++){
            if(step>0){
                step--;
                step=max(nums[i],step);
            }else{
                return false;
            }
        }
        
        return true;
        //本题我觉得一个需要考虑的就是最后的i条件判断是i<nums.size()，而不是i<nums.size()-1；
        //究其原因，我认为觉得可能出现[0,1]的可能性。
    }
};
