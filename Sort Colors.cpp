class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,two=nums.size()-1;
        for(int i=0;i<=two;i++){
            if(nums[i]==0){
                swap(nums[i],nums[zero++]);
            }
            if(nums[i]==2){
                swap(nums[i--],nums[two--]);
            // i-- 是因为从最远处换了一个未知颜色，需要i再次回到那个位置，进行比较
            //two--是因为之前的two位置已经是这个颜色，下次不需要判断成这个为位置了
            }
        }
    }
};
//  i-- 没有考虑到，if(nums[i]==0) 则不需要考虑，因为他换的只可能是1或者0,2已经被换到最右边
//一次ac啊
