class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);
        if(nums.empty()||target<nums[0]||target>nums[nums.size()-1])
            return res;
        int i=binaryLow( nums, target, 0 , nums.size()-1);
        int j=binaryHigh( nums, target, 0 , nums.size()-1);
        if(i<=j){//仔细想想，第一个是找小于等于的，第二个是找大于等于的
            res[0]=i;
            res[1]=j;
        }
        return res;
    }
    
    int binaryLow(vector<int>& nums,int target,int i,int j){
        if(i>j)
            return i;
        int mid=(i+j)/2;
        if(nums[mid]<target)
            return binaryLow(nums,target,mid+1,j);
        else
            return binaryLow(nums,target,i,mid-1);
    }
    
    int binaryHigh(vector<int>& nums,int target,int i,int j){
        if(i>j)
            return j;
        int mid=(i+j)/2;
        if(nums[mid]>target)
            return binaryHigh(nums,target,i,j-1);
        else
            return binaryHigh(nums,target,i+1,j);
    }
};

class Solution2 {
public:
int pos=-1;
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result1;
        
        pos=BinarySearch(nums,target,0,nums.size()-1);
        if(pos==-1){
            vector<int> result;
            result.push_back(-1);result.push_back(-1);
            return result;
        }
        
        int i,j;
        //往左

        i=pos;
        while(nums[i]==target&&i>=0){
            i--;
        }
        //往右
        j=pos;
        while(nums[j]==target&&j<=nums.size()-1){
            j++;
        }
        result1.push_back(i+1);
        result1.push_back(j-1);
        
        return result1;
    }
    
    int BinarySearch(vector<int> &nums,int val,int left,int right){
        int mid=(left+right)/2;//递归调用
        if(nums[mid]==val){
            return mid;
        }
        if(left>right){
            return -1;
        }
        if(nums[mid]<val){
            return BinarySearch(nums,val,mid+1,right);
        }
        else{
            return BinarySearch(nums,val,left,mid-1);
        }
    }
};
