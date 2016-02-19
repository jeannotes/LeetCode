class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		buildhelper(0,nums.size()-1,nums);
	}

	TreeNode* buildhelper(int start,int end,vector<int>&nums){
		if (start>end){
			return NULL;
		}
		int mid=(start+end)/2;
		root->left=buildhelper(start,mid-1,nums);
		TreeNode *root=new TreeNode(nums[mid]);
		root->right=buildhelper(mid+1,end,nums);
		return root;
	}
};
// 还需要多加练习
