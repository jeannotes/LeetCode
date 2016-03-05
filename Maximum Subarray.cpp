class Solution {
public:
//http://www.tuicool.com/articles/IbiMjaI
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0],res=nums[0];
        for(int i=1;i<nums.size();i++){
            sum=sum<0?(nums[i]):(sum+nums[i]);
            res=max(res,sum);
        }
        return res;
    }
};

class Solution {
public:
    int recursiveMaxSubArray(vector<int>&A, int left, int right)
    {
    	if(left == right)return A[left];
    	if(left == right-1)return max(max(A[left], A[right]), A[left]+A[right]);
    
    	//divide
    	int mid = (left + right)/2;
    	int lmax = recursiveMaxSubArray(A, left, mid-1);
    	int rmax = recursiveMaxSubArray(A, mid+1, right);
    
    	//the max is [i..mid..j]
    	int mmax = A[mid];
    
    	for(int j = mid + 1, sum = mmax; j <= right; ++j)
    	{
    		sum += A[j];
    		if(sum > mmax)
    			mmax = sum;	
    	}
    	
    	for(int j = mid - 1, sum = mmax; j >= left; --j)
    	{
    		sum += A[j];
    		if(sum > mmax)
    			mmax = sum;
    	}
    
    	return max(max(lmax, rmax), mmax);
    }
    
    int maxSubArray(vector<int>& nums) 
    {
    	return recursiveMaxSubArray(nums, 0, nums.size()-1);
    }
};
//  假设前面k个是sum，第k+1个的时候，如果sum小于0，对我后面计算是没有好处的，但是前提是之前的最大和已经保存在maxSum里面啦。
//所以会和前面的去比较的，没事
//注意LCS,LIS等问题
//第二种解法还有问题
