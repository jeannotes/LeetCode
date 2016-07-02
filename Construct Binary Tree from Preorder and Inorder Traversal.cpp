class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	return buildHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* buildHelper(vector<int>& preorder,int preStart,int preEnd,
    	vector<int>& inorder,int inStart,int inEnd) {
    	if (preStart > preEnd || inStart > inEnd)
    		return NULL;
    	int k = inStart;
    	for (; k <= inEnd;k++) {
    		if (inorder[k]==preorder[preStart])
    			break;
    	}
    	TreeNode* res = new TreeNode(preorder[preStart]);
    	res->left = buildHelper(preorder, preStart + 1, preStart + k - inStart,inorder,inStart,k-1 );
    	res->right = buildHelper(preorder, preStart + k - inStart + 1, preEnd, inorder, k + 1, inEnd);
    	return res;
    }
};
// 这个是好题目，在最后递归地方从哪里开始那边，start是哪个，end是哪个，要分清楚哦
// 基本没问题啦
