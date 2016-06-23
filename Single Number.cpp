class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
		unordered_map<int,int>num;
		for (int i=0;i<nums.size();i++){
			if (!num.count(nums[i])){
				num[nums[i]]=1;
			}else
				num.erase(nums[i]);
		}
		return num.begin()->first;
	}
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res^=nums[i];
        }//0与任何数字异或还为他本身，再次异或又是0.
        return res;
    }
};
// 没有同或运算符 d=!(a^b) 
// 可以啦，嘿嘿
