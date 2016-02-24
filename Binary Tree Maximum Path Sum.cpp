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
    int sum=INT_MIN;
    int maxPathSum(TreeNode* root) {
		pathsumHelper(root);
		return sum;
	}

	int pathsumHelper(TreeNode* root){
		if (root==NULL){
			return 0;
		}
		int left=max(0,pathsumHelper(root->left));
		int right=max(0,pathsumHelper(root->right));

		sum=max(sum,left+right+root->val);
		return root->val+max(right,left);
	}
};
        //首先tem的功能就是左边加上节点加上右节点，更新整体的res值。
        //至于函数返回值，返回的应该是加上本节点与左右子树的最大值。
        //我们定义函数返回值为根节点到左右两边，只能是单边的最大值，res是一直在更新的
        //函数的意思是从本节点到某一个节点的最大值，一定有本节点。
