class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return 1;
        sort(nums.begin(),nums.end());
        int len=0,count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[len]){
                count=1;
                len++;nums[len]=nums[i];
            }else{
                if(count<2){
                    len++;
                    nums[len]=nums[i];
                    count++;
                }
            }
        }
        return len+1;
    }
};
