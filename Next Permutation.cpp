class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0&&nums[i]>=nums[i+1])   i--;//此时的i代表第一个比下面一个数小的index
        // 1 2 8 7 4 3  -->  
        // 1 3 8 7 4 2  -->
        // 1 3 2 4 7 8
        if(i>=0){
            //说明可以比较
            int j=i+1;
            while(j<=nums.size()-1&&nums[j]>nums[i]){
                j++;
            }
            j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums,i+1);
        
    }
    
    void reverse(vector<int>& nums,int index){
        int start=index,end=nums.size()-1;
        while(start<=end){
            swap(nums[start],nums[end]);start++;end--;
        }
    }
};
