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


//迭代版本，可能我这个是最简单的吧
//一大早写了一个，非常方便，直接AC，非常开心
class Solution
{
public:
	vector<int> preorderTraversal(TreeNode *p){
		stack<TreeNode* > s;
		s.push(p);
		
		vector<int> result;

		while (!s.empty())//true--空  false--不空
		{
			p=s.top();s.pop();
			
			if(p==NULL)
				continue;
			result.push_back(p->val);
			
			s.push(p->right);			
			s.push(p->left);
			
		}
		return result;
	}
};
