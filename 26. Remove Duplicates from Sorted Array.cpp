class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for(int i=0;i<nums.size();i++){
            if(len<1 || nums[i]>nums[len-1])
                nums[len++] = nums[i];
        }
        return len;
    }
};
//一次通过
