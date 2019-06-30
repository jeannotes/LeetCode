class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()) return res;
        
        int i=0,j=nums.size()-1,mid=(i+j)/2;
        bool find = false;
        while(i<=j){
            mid=(i+j)/2;
            if(nums[mid]==target){
                find=true;
                break;
            }else if(nums[mid]>target){
                j=mid-1;
            }else if(nums[mid]<target){
                i=mid+1;
            }
        }
        if(find){
            int i=mid;
            for(i=mid;i>=0;i--){
                if(nums[i]!=target) break;
            }
            int j=mid+1;
            for(;j<=nums.size()-1;j++){
                if(nums[j]!=target) break;
            }
            res[0] = i+1;
            res[1]=j-1;
        }
        return res;
    }
};
