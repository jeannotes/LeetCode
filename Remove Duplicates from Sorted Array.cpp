class Solution {
//Remove Duplicates from Sorted Array
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
public:
	int removeDuplicates(vector<int>& nums){
		int len=nums.size();
		if (len<2){
			return len;
		}
		int n=0;
		//一方面做其实位置，一方面做标记，有几个数字
		//程序厉害的地方在于，设置了和这一区间段相同最后一位的后一位数字不同索引值。
		//并且直接保存到数组里面，方便比较。
		for (int i=1;i<len;i++){
			if (nums[i]!=nums[n]){
				nums[++n]=nums[i];
			}
		}
		return n+1;
	}
};
