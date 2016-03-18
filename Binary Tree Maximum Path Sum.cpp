class Solution {
public:
    int sum=INT_MIN;
    int maxPathSum(TreeNode* root) {
    	if (root==NULL){
    		return 0;
    	}
    	maxPathSumHelper(root);
    	return sum;
    }
    
    int maxPathSumHelper(TreeNode* root){
    	if (root==NULL){
    		return 0;
    	}
    	int left=max(0,maxPathSumHelper(root->left));
    	int right=max(0,maxPathSumHelper(root->right));
    
    	sum=max(sum,left+right+root->val);
    	return  root->val+max(left,right);
    }
};
        //首先tem的功能就是左边加上节点加上右节点，更新整体的res值。
        //至于函数返回值，返回的应该是加上本节点与左右子树的最大值。
        //我们定义函数返回值为根节点到左右两边，只能是单边的最大值，res是一直在更新的
        //函数的意思是从本节点到某一个节点的最大值，一定有本节点。
//不会啊
//稍微理解一点，函数的意思是  返回从当前节点往左走或者往右走的最大值
