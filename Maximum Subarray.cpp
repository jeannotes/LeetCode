class Solution {
public:
//还有一种分治法，第二次刷的时候补上
//https://leetcode.com/problems/maximum-subarray/
    int maxSubArray(vector<int>& nums) {
        int sum[nums.size()];
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum[i]=max(sum[i-1]+nums[i],nums[i]);
            res=max(res,sum[i]);
        }
        //sum[i]--代表以nums[i]为结尾的最大和
        return res;
    }
};
