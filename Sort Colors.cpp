class Solution{
public:
    void sortColors(vector<int>& nums) {
        int len=nums.size();
        int zero=0,two=len-1;
        
        for(int i=0;i<=two;i++){
            if(nums[i]==0) 
                swap(nums[i],nums[zero++]);
            if(nums[i]==2){
                swap(nums[i],nums[two]);
                two--;i--;//i的值已经变换，需-1，继续判断
            }
        }
    }
};
