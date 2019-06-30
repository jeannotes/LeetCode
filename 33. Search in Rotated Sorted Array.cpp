class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>=nums[i]){
                //leftside
                //当我确定好左边还是右边之后，假设右边，如果逼近下来nums[mid]<target&&target<=nums[j]
                //就在这一种情况下，i=mid+1,其余的统统是j=mid-1;
                //不需要管究竟在左边的上面还是下面
                if(nums[i]<=target&&target<nums[mid])
                    j=mid-1;
                else
                    i=mid+1;
            }else{
                if(nums[mid]<target&&target<=nums[j])
                    i=mid+1;
                else
                    j=mid-1;
            }
        }
        return -1;
    }
};
// bug-exist .. if(nums[mid]>=nums[i]) 等于号不能没有
//基本一次通过，加油
//通过啦
