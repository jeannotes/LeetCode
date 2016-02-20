class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		unordered_set<int>mp;
		for (int i=0;i<nums.size();i++){
			mp.insert(nums[i]);
		}
		int res=0;
		for (int i=0;i<nums.size();i++){
			int count=1;
			for (int j=nums[i]+1;mp.find(j)!=mp.end();j++){
				count++;mp.erase(j);
			}
			for (int j=nums[i]-1;mp.find(j)!=mp.end();j--){
				count++;mp.erase(j);
			}res=max(res,count);
			if(mp.size()<1)
			    break;
		}
		return res;
	}
};
