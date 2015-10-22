class Solution {
public:
//https://leetcode.com/problems/permutations-ii/
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> >result;
        permuteHelper(0,nums,result);
        return result;
    }
   
    void permuteHelper(int start,vector<int>& nums,vector<vector<int> >&result){
        if(start==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(i==start||!findDuplicates(nums[i],start,i,nums)){
                swap(nums[i],nums[start]);
                permuteHelper(start+1,nums,result);
                swap(nums[i],nums[start]);
            }
            //举例说明，1，1，2第一个选择1，没事，第一个选择不作要求，肯定不会相同，但是第二个
            //我就要比较了，因为start是1，第二个也是1，前面已经有去，再来一个就会重复。
            //就和数学里面排列组合一样。携程计算机语言就是第i次交换的时候，与后面第j个数字交换，得看[i...j-1]
            //是否还有重复数字，有重复不进行任何操作
        }
    }
    
    bool findDuplicates(int target,int start,int end,vector<int>& nums){
        for(int i=start;i<end;i++){
            if(nums[i]==target){
                return true;
            }
        }
        return false;
    }
};
