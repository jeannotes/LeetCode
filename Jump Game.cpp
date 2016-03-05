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
// 还是没有搞清楚，在循环里面先是step--，再去比较step是否大于0 
// 应该这样想1 2 3 既然step>0，那么有能力走到下一步，那么就减去1，和当前最大步数比较
//这一遍还行
//不会啊
