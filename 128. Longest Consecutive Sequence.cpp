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
// 丫丫，小错误不断啊 yanse bianhua a 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int cur=1, res=1;
        for(int i=1;i<nums.size() ;i++){
            if(nums[i]!=nums[i-1]){ 
                if(nums[i]==nums[i-1]+1){
                    cur++;
                    }
                else{
                    
                    cur=1;
                }
                res=max(res,cur);
            }
        }
        res=max(res, cur);
        return res;
    }
};
