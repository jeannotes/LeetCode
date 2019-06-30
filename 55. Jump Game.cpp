class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index=0;
        int n=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(index<i || index >=n) break;
            index = max(index, i+nums[i]);
        }
        
        return (index>=n)?1:0;
    }
};
//http://bangbingsyb.blogspot.com/2014/11/leetcode-jump-game-i-ii.html
