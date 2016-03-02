class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int len=0,count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[len]){
                nums[++len]=nums[i];
                count=1;
            }else if(count==1){
                nums[++len]=nums[i];
                count=2;
            }
        }
        return len+1;
    }
    //bug-free
};
//一次通过
