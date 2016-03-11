vector<int> twoSum(vector<int>& nums, int target) {
	vector<int>res;
	if (nums.empty()){
		return res;
	}
	unordered_map<int,int>number;
	for (int i=0;i<nums.size();i++){
		int tmp=target-nums[i];
		if (number.find(tmp)!=number.end()){
			res.push_back(number[tmp]);
			res.push_back(i);
			break;
		}else
			number[nums[i]]=i;
	}
	return res;
}
//题目不难，使用hash表，再次强调，学习STL，把几个map的函数学会啊
