class Solution {
//https://leetcode.com/problems/first-missing-positive/
public:
    int firstMissingPositive(vector<int>& nums) {
        // 1-a[0] 2-a[1] 3-a[2]   桶排序
        // 注意下面变换顺序
        if(nums.size()<1)   return 1;
        int num;
        for(int i=0;i<nums.size();i++){
            //if(nums[i]<=0)  continue;
            num=nums[i];
            while(num>0&&num<nums.size()&&num!=nums[num-1]){
                swap(nums[num-1],nums[i]);
                num=nums[i];
            }//这边似乎就已经全部排列好了
        }
        //转换结束
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }//本来数组就2个数，[2,1],循环结束。
        return nums.size()+1;
    }
};
//bug-exist  在while那个循环那边  nums[i]>0&&nums[i]<=len 这两个条件没有看到
