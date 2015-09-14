class Solution {
//Remove Duplicates from Sorted Array II
//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
public:
	int removeDuplicates(vector<int>& nums){
		int n=nums.size();
		if(n<2)
			return n;
		else
		{
			int len=0;
			int j=0;
			for (int i = 1; i < n; i++)
			{
				if (nums[i]!=nums[len])
				{
					len++;
					nums[len]=nums[i];
					j=0;
				}
				else
				{
					if (j==1)
					{
						//j=1表明已经有二次了						
						continue;
					}
					else
					{
						j=1;
						len++;
						nums[len]=nums[i];
					}
				}
			}
			return len+1;
		}		
	}
};
//本题目一开始卡在出现[1 1 1 1 ]的情况，后来[1 1 2 2]又没有考虑到，这才在第一个if循环中添加j=0这个条件。
//最主要就是j=0这个条件放错位置
