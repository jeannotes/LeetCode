class Solution {
//https://leetcode.com/problems/3sum-closest/
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res=INT_MAX,result=target;
        for(int i=0;i<=nums.size()-3;i++){//每次都是缺一个，缺两个的错误
            //本质上与3sum相同
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int sum=nums[right]+nums[left]+nums[i];
                if(sum==target)
                    return target;
                else{
                    if(abs(sum-target)<res){
                        res=abs(sum-target);
                        result = sum;
                    }
                    if(sum>target)
                        right--;
                    if(sum<target)
                        left++;
                }
            }
        }
        return result;
    }
};
//好题目啊，不会
/*
if(sum>target)
    right--;
if(sum<target)
    left++;         这个地方容易出错啊 left++;  right--;容易判别错误
*/ 
//基本没问题
