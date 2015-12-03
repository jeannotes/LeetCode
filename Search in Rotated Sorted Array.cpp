class Solution {
public:
//https://leetcode.com/problems/search-in-rotated-sorted-array/
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        //找到第一个变小的值下，写一个新函数
        int left=0,right=len-1;
        int f=findFirstBig(nums);
        if(f==0){
            return binareSearch(f,len,nums,target);
        }else{
            if(nums[f-1]>=target){
                left= binareSearch(0,f-1,nums,target);
                if(left!=-1) return left;
            }
            if(nums[f]<=target){
                right= binareSearch(f,len-1,nums,target);
                if(right!=-1) return right;
            }
            
            return -1;
        }
        
    }
    
    //二分查找
    int binareSearch(int i,int j,vector<int>& nums,int target){
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
            return -1;
        }
    }
    
    //找到第一个减小的数值
    int findFirstBig(vector<int>& nums){
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(i>0&&nums[i]<nums[i-1]){
                return i;
            }
        }
        return 0;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target)   return mid;
            if(nums[mid]>=nums[left]){
                //在左边
                if(target>=nums[left]&&target<nums[mid])   
                    right=mid-1;
                else
                    left=mid+1;
            }else{
                //在右边
                if(target<=nums[right]&&nums[mid]<target)
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return -1;
    }
};
