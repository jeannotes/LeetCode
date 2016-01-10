class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=0)
            return 0;
        int len=0,count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[len]){
                count=0;
                nums[len++]=nums[i];
                count++;
            }else{
                if(count==1){
                    len++;
                    nums[len]=nums[i];
                    count++;
                }
            }
        }
        return len+1;
    }
};
