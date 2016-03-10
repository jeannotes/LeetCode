class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
            return 0;
        int len=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val)
                nums[len++]=nums[i];//1 2 3 4 
        }
        return len;
        //为什么是len而不是len+1，
        //在nums数组中，只要不相同，就会从一开始重新赋值,而之后len会+1，所以不需要最后len+1
        //bug-exist  return len+1
    }
};
//一次通过
