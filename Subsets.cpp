class Solution {//https://leetcode.com/problems/subsets/
	//第三遍的时候注意一下位操作法
public:
    vector<vector<int>>res;
    vector<int>tem;
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        res.push_back(vector<int>());
        subsetsHelper(0,nums);
        return res;
    }
    
    void subsetsHelper(int start,vector<int>&nums){
        if(start==nums.size())
            return;
        
        for(int i=start;i<nums.size();i++){
            tem.push_back(nums[i]);
            res.push_back(tem);
            subsetsHelper(i+1,nums);//不是start，每次都会出错
            tem.pop_back();
        }
    }
};
//不会,还是没有做出来啊
//会了，总算会了,空集合没有注意
// 思路已经有，但是还是会出错
