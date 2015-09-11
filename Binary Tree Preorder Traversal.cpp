//如今总算是有一次发现 vector<int> &result中不加&出现问题了。
//写递归程序一定注意终止条件
//一开四 preoderHelper 中 我写的
//  if(root!=NULL)  result.push_back(root->val)
//144--Binary Tree Preorder Traversal 
//https://leetcode.com/problems/binary-tree-preorder-traversal/
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


//迭代版本，可能我这个是最简单的吧
//一大早写了一个，非常方便，直接AC，非常开心
//BTW，这是第二个修改版本
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root){
		stack<TreeNode*> s;
		vector<int> result;
		s.push(root);

		while (!s.empty())
		{
			root=s.top();s.pop();
			if (root==NULL)
				continue;
			//虽然检测栈是不是空的，但不能确定结点是否为空
			result.push_back(root->val);
			s.push(root->right);
			s.push(root->left);
		}
		return result;
	}
	
};
