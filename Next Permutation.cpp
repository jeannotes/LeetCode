class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 1 4 6 5 2 0
        if(nums.empty())
            return;
        int i=nums.size()-2;
        for(;i>=0;i--){
            if(nums[i]<nums[i+1])
                break;
        }
        if(i>=0){
            //记住一个案例,一开始从后往前，先找到第一个比后面小的，能够保证后面的数字从后往前递增
            //接下来，比较从下一个位置开始，谁第一个小雨他，看实例即可
            // 1 3 5 4 2 0 
            int j=i+1;
            while(j<nums.size()&&nums[j]>nums[i]){
                j++;
            }
            j--;
            swap(nums[i],nums[j]);
        }
        reverse_(nums,i+1);
    }
    
    void reverse_(vector<int>& nums,int index){
        int start=index,end=nums.size()-1;
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;end--;
        }
    }
};
//出错原因，由于没有考虑到1 1 5这种情况，需要考虑重复数字
// 基本没问题，编程技巧还有问题，现在不知道怎么应对115 这种情况
/*
while(j<nums.size()&&nums[j]>nums[i])  对应1 5 1 一定是--nums[j]>nums[i]  而不是nums[j]>=nums[i]
等于的情况不可取
*/
