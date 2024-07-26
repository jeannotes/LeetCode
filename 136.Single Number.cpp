class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> u_map;
        for(int i=0; i<nums.size(); i++){
            if(u_map.find(nums[i]) == u_map.end()) u_map[nums[i]]=1;
            else u_map[nums[i]]=u_map[nums[i]]+1;
        }
        for(int i=0; i<nums.size(); i++){
            if(u_map[nums[i]] != 1) u_map.erase(nums[i]);
        }
        return u_map.begin()->first;
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
