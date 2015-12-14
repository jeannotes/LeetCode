class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        
        int low=binarySearchLow(nums,target,0,nums.size()-1);
        int high=binarySearchHigh(nums,target,0,nums.size()-1);
        
        if(low<=high){
            result[0]=low;
            result[1]=high;
            return result;
        }
        return result;
    }
    
    int binarySearchLow(vector<int> &nums,int target,int left,int right){
        if(left>right){//关键的判断
            return left;
        }
        int mid=(left+right)/2;
        if(nums[mid]<target){//这个地方不能有等于号，有等于号，而且如果只有1个mid，就再也回不来
            return binarySearchLow(nums,target,mid+1,right);
        }else{
            return binarySearchLow(nums,target,left,mid-1);
        }
        //写这个函数的时候思路是这样的：我先将if的两个情况写下来，再对应题目可能情况修改。
    }
    
    int binarySearchHigh(vector<int> &nums,int target,int left,int right){
        if(left>right){
            return right;
        }
        int mid=(left+right)/2;
        if(nums[mid]>target){//这个地方不能有等于号，有等于号，而且如果只有1个mid，就再也回不来
            return binarySearchHigh(nums,target,left,mid-1);
        }else{
            return binarySearchHigh(nums,target,mid+1,right);
        }
        //写这个函数的时候思路是这样的：我先将if的两个情况写下来，再对应题目可能情况修改。
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
