class Solution {
//https://leetcode.com/problems/jump-game-ii/
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int max=0,sum=0,start=1;
        for(int i=0;i< n;i++){
            if(i>=start){
                start=max+1;
                sum++;
            }
            if(i+nums[i]>max){
                max=i+nums[i];
            }
        }
        return sum;
    }
};
