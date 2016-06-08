class Solution1 {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);
        if(nums.empty()||target<nums[0]||target>nums[nums.size()-1])
            return res;
        int i=binaryLow( nums, target, 0 , nums.size()-1);
        int j=binaryHigh( nums, target, 0 , nums.size()-1);
        if(i<=j){//仔细想想，第一个是找小于等于的，第二个是找大于等于的
            res[0]=i;
            res[1]=j;
        }
        return res;
    }
    
    int binaryLow(vector<int>& nums,int target,int i,int j){
        if(i>j)
            return i;
        int mid=(i+j)/2;
        if(nums[mid]<target)
            return binaryLow(nums,target,mid+1,j);
        else
            return binaryLow(nums,target,i,mid-1);
    }
    
    int binaryHigh(vector<int>& nums,int target,int i,int j){
        if(i>j)
            return j;
        int mid=(i+j)/2;
        if(nums[mid]>target)
            return binaryHigh(nums,target,i,j-1);
        else
            return binaryHigh(nums,target,i+1,j);
    }
};
//  bug  在大于等于和小于等于方面存在问题
//  如果找不到的话是 i>j的，要找到这个规律


//迭代的版本
vector<int>res;
vector<int> searchRange(vector<int>& nums, int target) {
	int i = searchLeft(nums, target);
	int j = searchRight(nums, target);
	res.push_back(i);
	res.push_back(j);
	return res;
}

int searchLeft(vector<int>& nums, int target) {
	int i = 0, j = nums.size() - 1;
	while (i<=j){
		int mid = (i + j) / 2;
		if (nums[mid] < target)
			i = mid + 1;//11
		else
			j = mid - 1;
	}
	return nums[i] == target ? i : -1;
}

int searchRight(vector<int>& nums, int target) {
	int i = 0, j = nums.size() - 1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (nums[mid] > target)
			j = mid - 1;//11
		else
			i = mid + 1;
	}
	return nums[j] == target ? j : -1;
}
// 这个版本更好
