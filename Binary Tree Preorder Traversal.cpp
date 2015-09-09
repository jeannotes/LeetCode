//如今总算是有一次发现 vector<int> &result中不加&出现问题了。
//写递归程序一定注意终止条件
//一开四 preoderHelper 中 我写的
//  if(root!=NULL)  result.push_back(root->val)

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root){
		vector<int > result;
		preorderHelper(root,result);
		return result;
	}

	void preorderHelper(TreeNode *root,vector<int> &result){
		if(root==NULL)
		    return;
		result.push_back(root->val);
		preorderHelper(root->left,result);
		preorderHelper(root->right,result);
	}
};
