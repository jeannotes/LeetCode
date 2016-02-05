class Solution1 {
public:
//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
    bool search(vector<int>& nums, int target) {
        int len=nums.size();
        //找到第一个变小的值下，写一个新函数
        int left=0,right=len-1;
        int f=findFirstBig(nums);
        if(f==0){
            return binareSearch(f,len,nums,target);
        }else{
            if(nums[f-1]>=target){
                left= binareSearch(0,f-1,nums,target);
                if(left!=false) return left;
            }
            if(nums[f]<=target){
                right= binareSearch(f,len-1,nums,target);
                if(right!=false) return right;
            }
            
            return false;
        }
        
    }
    
    //二分查找
    int binareSearch(int i,int j,vector<int>& nums,int target){
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]<target){
                i=mid+1;
            }
            if(nums[mid]>target){
                j=mid-1;
            }
        }
        if(i>j){
            return false;
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
//说明：分成两个区间之后，还得考虑下target是不是在左边还是在右边    
public:
    bool search(vector<int>& nums, int target) {//还是没有能够理解啊
        if(nums.empty())
            return -1;
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target)   
                return true;
            if(nums[mid]>nums[left]){
                //在左边
                if( target<nums[mid] && nums[left]<=target ){
                    right=mid-1;
                }else 
                    left=mid+1;
            }else if(nums[mid]<nums[left]){
                if(target <=nums[right] && nums[mid]<target ){
                    left=mid+1;
                }else 
                    right=mid-1;
            }else
                left++;//非常重要的地方
        }
        return false;
    }
};
//1 1 5 1 1 1 1
//找一个特殊例子
