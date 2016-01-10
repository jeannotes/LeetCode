class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=0)
            return 0;
        int len=0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[len]){
                len++;
                nums[len]=nums[i];
            }
        }
        return len+1;
    }
};
		//一方面做其实位置，一方面做标记，有几个数字
		//程序厉害的地方在于，设置了和这一区间段相同最后一位的后一位数字不同索引值。
		//并且直接保存到数组里面，方便比较。
