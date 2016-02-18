/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
		TreeNode *root=new TreeNode(nums[mid]);
		root->left=buildhelper(start,mid-1,nums);
		root->right=buildhelper(mid+1,end,nums);
		return root;
	}
};
