class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int len=nums.size();
        if(target<nums[0])
            return 0;
        if(target>nums[len-1])
            return len;
        //这个时候保证一定在里面
        int i=0,j=len-1,mid=0;
        while(i<=j){
            mid=(i+j)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                j=mid-1;
            if(nums[mid]<target)
                i=mid+1;
        }
        return i;//1 3 5 7
    }
};
//  return i这边不能理解  这一次竟然把j=mid-1 写成i-1
// 要弄清楚为什么返回i，两次转换  i,i+1,->,i+1,i+1,->,i+1,i  s所以最后返回i就行
// 现在这题没什么大问题啦
