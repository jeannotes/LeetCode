class Solution {
public:
    vector<vector<int>>res; 
    vector<vector<int>> levelOrder(TreeNode* root) {
    	if (root == NULL)
    		return res;
    	queue<TreeNode*>q;
    	q.push(root);
    	while (!q.empty()){
    		int size = q.size();
    		vector<int>tem1;
    		for (int i = 0; i < size;i++) {
    			TreeNode* tem = q.front(); q.pop();
    			if (tem->left)
    				q.push(tem->left);
    			if (tem->right)
    				q.push(tem->right);
    			tem1.push_back(tem->val);
    		}
    		res.push_back(tem1);
    	}
    	return res;
    }
};
//不能捡了西瓜丢了芝麻, int n=q.size(); 这句话不能少，感觉还不错啊
//  我用的是栈，本题不能用栈，不然顺序出错哦，我用的是队列，还不错
