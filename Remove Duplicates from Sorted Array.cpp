class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int len=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[len]){
                nums[++len]=nums[i];
            }
        }
        return len+1;
        //对比remove element，这里可以这样思考
        //如果全部为1，一开始len是0，最后仅仅保留一个自然要+1输出
    }
};
