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
class Solution2 {
public:
    vector<int>res;
    vector<int> preorderTraversal(TreeNode* root) {
    	if (root == NULL)
    		return res;
    	stack<TreeNode*>stk;
    	while (root||!stk.empty()){
    		while (root){
    			stk.push(root); 
    			res.push_back(root->val);
    			root = root->left;
    		}
    		root = stk.top()->right; 
    		stk.pop();
    	}
    	return res;
    }
};
//非递归不会啊，不会啊
//https://leetcode.com/discuss/100858/preorder-inorder-postorder-iterative-solution-by-c
//  要么就if else  不然就只能是两个while语句啦，加油啊
//c擦，问题还是很大
