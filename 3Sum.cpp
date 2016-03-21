class Solution {
//https://leetcode.com/problems/3sum/
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >res;
        if(nums.size()<3)   return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size()-3;i++){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1,right=nums.size()-1;
            
            while(left<right){注意这里不能写等于号，不然会导致相同的数字。
                int sum=0-nums[i];
                int curSum=nums[left]+nums[right];
                if(sum==curSum){
                    vector<int> temp;
                    temp.push_back(nums[i]);temp.push_back(nums[left]);temp.push_back(nums[right]);
                    res.push_back(temp);
                    
                    left++;right--;
                    while(nums[left]==nums[left-1])
                        left++;
                    while(nums[right]==nums[right+1])
                        right--;
                }
                if(sum>curSum){
                    left++;
                }
                if(sum<curSum){
                    right--;
                }
            }
        }
        return res;
    }
};
// 这才是好题目啊
//可惜不会啊
//第二天早晨做，一次通过
//  这个分支 if(sum==curSum)  里面没 往右往左走
//  在里面定义vector<int> tem; 不然需要清空的
// 今天终于一次acc
