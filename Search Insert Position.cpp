class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length=nums.size();
        int i=0,j=length-1;
        
        if(nums[0]>target){
            return 0;
        }
        
        if(nums[length-1]<target){
            return length;
        }
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                i=mid+1;
            }
            if(nums[mid]>target){
                j=mid-1;
            }
        }
        
        if(i>j){
            return i;
        }
    }
};
