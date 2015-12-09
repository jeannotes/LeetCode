class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
//本质上与之前的remove duplicates 是相同的思路。
        if(nums.empty())
            return 0;
        int len=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val)
                nums[len++]=nums[i];
        }
        return len;
    }
};
