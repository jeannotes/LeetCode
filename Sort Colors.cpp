class Solution1 {
//https://leetcode.com/problems/sort-colors/
public:
	void sortColors(vector<int>& nums) {
		int len=nums.size();
		int one=0,two=len-1;

		for (int i=0;i<=two;i++){
			if (nums[i]==0){
				swap(nums[i],nums[one]);
				one++;
			}
			if (nums[i]==2){
				swap(nums[i],nums[two]);
				two--;
				i--;
			}
		}
		
	}
};


class Solution2 {
public:
	void sortColors(vector<int>& nums) {
		int len=nums.size();
		int one=0,two=0,three=0;

		for (int i=0;i<len;i++){
			if (nums[i]==0){
				swap(nums[i],nums[one]);
				one++;
			}
		}
		//第二次
		two=one;
		for (int i=one;i<len;i++){
			if (nums[i]==1){
				swap(nums[i],nums[two]);
				two++;
			}
		}
		//第二次
		three=two;
		for (int i=three;i<len;i++){
			if (nums[i]==2){
				swap(nums[i],nums[three]);
				three++;
			}
		}
	}
};
