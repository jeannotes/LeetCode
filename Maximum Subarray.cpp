class Solution {
public:
//http://www.tuicool.com/articles/IbiMjaI
    int maxSubArray(vector<int>& nums) {
    	int sum=nums[0],res=nums[0];
    	for (int i=1;i<nums.size();i++){
    		if (sum<0){
    			sum=0;
    		}
    		sum+=nums[i];
    		res=max(res,sum	);
    	}
    	return res;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
    	return maxSubHelper(nums,0,nums.size()-1);
    }
    
    int maxSubHelper(vector<int>&nums,int left,int right){
    	if (left==right){
    		return nums[left];
    	}
    	if (left==right-1){
    		return max( max(nums[left],nums[right]),nums[left]+nums[right] );
    	}
    	int mid=(left+right)/2;
    	int lmax=maxSubHelper(nums,left,mid-1);
    	int rmax=maxSubHelper(nums,mid+1,right);
    
    	int nmax=nums[mid];
    	for (int j=mid+1,sum=nums[mid];j<=right;j++){
    		sum+=nums[j]; //这个地方不写sum=max(sum,sum+nums[i])的原因是假设计算到第6位数字，而此时前三位最大，再加上第7位数字
    		                //就是前面三位加上第7位，就不是连续计算的。
    		nmax=max(nmax,sum);
    	}
    	for (int j=mid-1,sum=nmax;j>=left;--j){
    		sum+=nums[j];
    		nmax=max(nmax,sum);
    	}
    	return max( max(lmax,rmax),nmax  );
    }	

};
//  假设前面k个是sum，第k+1个的时候，如果sum小于0，对我后面计算是没有好处的，但是前提是之前的最大和已经保存在maxSum里面啦。
//不会啊，真的是好题目,好题目 至今不会啊，意思是如果第k个数字与前面的和是小于0的，那么就没有意义，则从头再来。 还是不会 

//最大子矩阵和 
int max_subarray(vector<int> &array) {
    int res = 0, sum = 0;
    for (int i = 0; i < array.size(); ++i) {
        sum += array[i];
        res = max(res, sum);
        sum = max(sum, 0);
    }
    return res;
}

int max_submatrix(vector<vector<int>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int res = 0;
    for (int r1 = 0; r1 < matrix.size(); ++r1) {
        vector<int> sum(matrix[0].size());
        for (int r2 = r1; r2 < matrix.size(); ++r2) {
            for (int c = 0; c < matrix[0].size(); ++c) {
                sum[c] += matrix[r2][c];
            }
            int t = max_subarray(sum);
            res = max(res, t);
        }
    }
    return res;
}
