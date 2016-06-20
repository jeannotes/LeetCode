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
    	}//其实这里没必要继续写if (root->left==NULL&&...)  
    	// 因为此时 假如返回的是root->val（也就是本节点） 其实是最大值啊 
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

//稍微理解一点，函数的意思是  返回从当前节点往左走或者往右走的最大值
// 多多少少比以前理解许多了啊
//  这里不能写成int maxPathSumHelper(TreeNode* root,int sum) 
//而 int sum应该是全局变量，如果写成局部变量，每次都要和左边节点的值比较
//而如果是全局变量，就是每次更新sum值，  所以看solution2
class Solution2 {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
    	maxHelper(root);
    	return res;
    }
    
    int maxHelper(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	if (root->left == NULL&&root->right == NULL) {
    		res = max(res, root->val);
    		return root->val;
    	}
    	int left = max(0, maxHelper(root->left));
    	int right = max(maxHelper(root->right), 0);
    	res = max(res, left + right + root->val);
    	return root->val + max(left, right);
    }
};

/*
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if (root->left == NULL&&root->right == NULL) {
    		res = max(res, root->val);
    		return res;
    	}
    	maxHelper(root);
    	return res;
    }
    
    int maxHelper(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	if (root->left == NULL&&root->right == NULL) {
    		//res = max(res, root->val);
    		return root->val;
    	}
    	int left = max(0, maxHelper(root->left));
    	int right = max(maxHelper(root->right), 0);
    	res = max(res, left + right + root->val);
    	return root->val + max(left, right);
    }
    本来 [0]就会导致程序出错，我在最开头 if (root->left == NULL&&root->right == NULL)   就是为了去除这种情况
    另外就是判断有哪些可能性是不符合这个要求的 [-2,1]就是其中一个啊。
    看了还是要验证res的最大值啊
*/
// 还是不会，这是好题目啊
