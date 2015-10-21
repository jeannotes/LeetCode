class Solution {
public:

    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> >result;
        
        int length=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<=length-3;i++){
            if(i>0&&nums[i-1]==nums[i]){
                continue;
            }
            //一开始误解程序意思，只要是后面有重复的，不考虑，因为那个第一个已经处理过
            
            int left=i+1,right=length-1;
            while(left<right){
                int sum=0-nums[i];
                int cursum=nums[left]+nums[right];
                if(cursum==sum){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    result.push_back(temp);
                    
                    left++;right--;
                    while(nums[left]==nums[left-1]){
                        left++;
                    }
                    while(nums[right]==nums[right+1]){
                        right--;
                    }//之前考虑了三个连在一起的情况，是这样的，如果两者连在一起，那就是正好插入进去，这个时候
                     //left++，right--，但不能够有重复的数字，所以这样足够，而我们所谓的出现三个数字相同的情况就是i，left，right是正好连在一起的了
                     
                }
                if(cursum<sum){
                    left++;
                }
                if(cursum>sum){
                    right--;
                }
            }
            
        }
        
        return result;
    }
    
};
