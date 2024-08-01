    int maxSubArray(vector<int>& nums) {
        int res = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res;
    }


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
            -2, 1,-3,4,-1,2,1,-5,4
            -2,-1,-1,4, 4
            -2,-1,-1,4, 4
        */
        vector<int>dp(nums);
        dp[0]=nums[0];
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = max(dp[i-1],0) + nums[i];
            res=max(res, dp[i]);
        }
        return res;
    }
};
//  假设前面k个是sum，第k+1个的时候，如果sum小于0，对我后面计算是没有好处的，但是前提是之前的最大和已经保存在maxSum里面啦。
//不会啊，真的是好题目,好题目 至今不会啊，意思是如果第k个数字与前面的和是小于0的，那么就没有意义，则从头再来。 还是不会 
// good
//最大子矩阵和  good idea
