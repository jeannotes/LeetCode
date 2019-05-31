class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(), nums.end());
        
        int len = nums.size();
        for(int i=0; i< len;i++){
            if(i>0 && nums[i-1]==nums[i])
                continue;
            int left = i+1, right = len-1;
            while(left<right){// 注意这里不能写等于号，不然会导致相同的数字。 DDD
                // may be equal
                int sum = nums[i] + nums[left] + nums[right];
                if(sum==0){
                    vector<int> temp1{nums[i], nums[left],nums[right]};
                    res.push_back(temp1);
                    
                    left++;
                    while(left<len && nums[left]==nums[left-1]) left++;//注意边界条件
                    right--;
                    while(right>=i &&nums[right+1]==nums[right]) right--;
                }else if(sum>0)
                    right--;
                else
                    left++;
            }
        }
        return res;
    }
};
// 这个分支 if(sum==curSum)  里面没 往右往左走,在里面定义vector<int> tem; 不然需要清空的.
// 竟然能够把 int sum=nums[i]+nums[left]+nums[right];  这句话放在外面
