class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int>res;
    	stack<TreeNode*>stk;
    
    	if (root==NULL){
    		return res;
    	}
    	TreeNode* last=NULL;
    	while (root!=NULL||!stk.empty()){
    		if (root!=NULL){
    			stk.push(root);
    			root=root->left;
    		}else{
    			TreeNode* n=stk.top();
    			if (n->right==NULL||last==n->right){
    				res.push_back(n->val);//如果为空，访问根节点，如刚刚访问右节点，访问根节点。
    				stk.pop();
    				last=n;
    			}else{
    				root=n->right;
    			}
    		}
    	}
    	return res;
    }
};


class Solution2 {
public:
    vector<int> postorderTraversal2(TreeNode *root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
    
    void postorderHelper(TreeNode *root, vector<int> &result) {
        if (root == NULL) return;
        postorderHelper(root->left, result);
        postorderHelper(root->right, result);
        result.push_back(root->val);
    }
};

class Solution3 {
public:
    vector<int>res;
    vector<int> postorderTraversal(TreeNode* root) {
    	if (root == NULL)
    		return res;
    	stack<TreeNode*>stk;
    	while (root||!stk.empty()){
    		if (root) {
    		    stk.push(root);
    			res.insert(res.begin(), root->val);
    			root = root->right;
    		}
    		else {
    			root = stk.top(); 
    			stk.pop(); 
    			root = root->left;
    		}
    	}
    	return res;
    }
};
//还是不太好啊
//  n,last 那边总是出错啊，root=n1->right
// 还是在n那边容易出错啊
