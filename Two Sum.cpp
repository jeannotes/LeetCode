class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int>res;
    	if (nums.empty()){
    		return res;
    	}
    	unordered_map<int,int>mp;
    	for (int i=0;i<nums.size();i++){
    		int tmp=target-nums[i];
    		if (mp.find(tmp)!=mp.end()){
    			res.push_back(mp[tmp]);res.push_back(i);
    			break;
    		}else
    			mp[nums[i]]=i;
    	}
    	return res;
    }
};
//题目不难，使用hash表，再次强调，学习STL，把几个map的函数学会啊
//不太会
//接连做了好几遍,感觉脑子进水了
//  不要在循环里面直接return啊
//1 

//以下是错误的解法
  /*  vector<int> res;
    vector<int> twoSum(vector<int>& nums, int target) {
    	if (nums.empty())
    		return res;
    	unordered_map<int,int>numbers;
    	for (int i=0;i<nums.size();i++){
    		numbers[nums[i]]=i;
    	}
    	for (int i=0;i<nums.size();i++){
    		if (numbers.find(target-nums[i])!=numbers.end()){
    			res.push_back(numbers[nums[i]]);
    			res.push_back(numbers[target-nums[i]]);
    			return res;
    		}
    	}
    }*/
//[3,2,4] 6  都能存进hash表，但是注意，d 当 6-3 恰好也等于3 这时候全部存0,0  所以出错 
//容易出错啊，小错误
// 加油，今天写出来了,almost ater 100 days to wrote leetcode

//python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lookup={}
        for count,elem in enumerate(nums):
            if target-elem in lookup:
                return [lookup[target-elem],count]
            lookup[elem]=count;
