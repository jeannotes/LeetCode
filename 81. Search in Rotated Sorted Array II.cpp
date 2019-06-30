class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(nums[mid]==target) return true;          
            if(nums[mid]>nums[i]){
                if(nums[i]<=target && target < nums[mid])
                    j=mid-1;
                else
                    i=mid+1;
            }
            else if(nums[mid]<nums[i]){
                if(nums[mid]<target && target<=nums[j])
                    i=mid+1;
                else
                    j=mid-1;
            } else{
                i++;
            }         
        }
        //https://www.bilibili.com/video/av55640026?from=search&seid=16902314324790709806
        //例子比较形象
        return false;
    }
};
//1 1 5 1 1 1 1
//找一个特殊例子
// 如果是 nums[mid]<nums[right]  nums[mid]>nums[right] right--
// 最怕在折叠点不能够确定是比左边大，还是比右边的小的啊
//允许重复元素，则上一题中如果{A[m]>=A[l]},那么{[l,m]}为递增序列的假设就不能成立了，比如{[1,3,1,1,1]}。 
// 还是得，每次都要google
