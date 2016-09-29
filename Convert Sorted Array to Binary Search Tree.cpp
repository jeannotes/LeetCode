class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
	return buildHelper(0,nums.size()-1,nums);
    }
	
    TreeNode* buildHelper(int start,int end,vector<int>& nums){
	if (start>end){
		return NULL;
	}
	int mid=(start+end)/2;
	TreeNode* node=new TreeNode(nums[mid]);
	node->left=buildHelper(start,mid-1,nums);
	node->right=buildHelper(mid+1,end,nums);
	return node;
    }
};
// 还需要多加练习  判断条件没有写啊
/*if (start>end){
		return NULL;
	}*/
//  这题会，但是下一题不会了 好题目
