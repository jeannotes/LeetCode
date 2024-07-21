class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1) return true;
        int curmax=0, end=0, ans=0;
        for(int i=0;i<nums.size()-1;i++){
            curmax=max(curmax, nums[i]+i);
            if(curmax<=i) return false;
            if(i==end){
                ans++;
                end=curmax;
            }
        }
        return curmax >= nums.size()-1;
    }
};
//https://blog.lichangao.com/daily_practice/leetcode/greedy/basis.html#_0055-%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F
