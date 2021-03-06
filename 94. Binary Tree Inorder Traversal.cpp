//https://leetcode.com/problems/binary-tree-inorder-traversal/
class Solution1 {
public:
    vector<int> inorderTraversal1(TreeNode* root){
        vector<int> result;
        inorderHelper(root,result);
        return result;
    }
    
    void inorderHelper(TreeNode *root,vector<int> &result){
        if(root==NULL) return;
        inorderHelper(root->left,result);
        result.push_back(root->val);
        inorderHelper(root->right,result);
    }
};

class Solution2 {
public:
    vector<int>res;
    vector<int> inorderTraversal(TreeNode* root) {
    	if (root == NULL)
    		return res;
    	stack<TreeNode*>stk;
    	while (root||!stk.empty()){
    		if (root) {
    			stk.push(root);
    			root = root->left;
    		}
    		else {
    			root = stk.top(); stk.pop();
    			res.push_back(root->val);
    			root = root->right;
    		}
    	}
    	return res;
    }
};
//还有小问题，非递归写法没问题啦，纪念一下，一次通过，递归写法还是不会啊
//晚上做了一遍 懵懵懂懂，一次通过啊，第二种方法务必掌握
// 非常棒啊，在听周杰伦的歌了，这个会，但是其他两个不会了，今天再做一遍
