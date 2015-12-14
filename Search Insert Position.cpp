class Solution1 {
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

class Solution2 {
public:
    int pos=0;
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int find=binarySearch(0,nums.size()-1,nums,target);
        
        if(find!=-1)
            return find;
        else
            return  pos; //1 2 4
    }
    
    int binarySearch(int left,int right,vector<int>&nums,int target){
        if (left>right){
            pos=(right+left+2)/2;
            //pos= left ;
            return -1;
        }
            
        int mid=(left+right)/2;
        
        if(nums[mid]==target)
            return mid;
        if(nums[mid]>target)
            return binarySearch(left,mid-1,nums,target);
        if(nums[mid]<target)
            return binarySearch(mid+1,right,nums,target);
    }
};
