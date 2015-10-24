class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int length=nums.size();
        sort(nums.begin(),nums.end());
        int left=0,right=length-1;
        int res=INT_MAX,result=target;
        for(int i=0;i<length-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            
            int a=nums[i];
            int left=i+1,right=length-1;
            while(left<right){
                int b=nums[left],c=nums[right];
                int sum=a+b+c;
                
                
                if(sum==target){
                    return target;
                }else{
                    if(abs(target-sum)<=res){
                        res=abs(target-sum);
                        result=sum;
                    }
                    
                    if(sum>target){
                        right--;
                        while(nums[right]==nums[right+1]){
                            right--;
                        }
                        
                    }
                    
                    if(sum<target){
                        left++;
                        while(nums[left]==nums[left-1]){
                            left++;
                        }
                    }
                }
                
            }
        }
        return result;
    }
};
