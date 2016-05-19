class Solution {
public:
    vector<vector<int>>res;
    vector<int>tem;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	pathHelper(root, sum);
    	return res;
    }
    
    void pathHelper(TreeNode* root,int sum) {
    	if (root == NULL)
    		return;
    	tem.push_back(root->val);
    	if (root->left == NULL&&root->right== NULL&&sum == root->val)
    		res.push_back(tem);//这个地方不能够加return //0 1 1 sum=1 加上return 返回 01 011
    	else {
    		pathHelper(root->left,sum-root->val);
    		pathHelper(root->right, sum - root->val);
    	}
    	tem.pop_back();
    }
};
//其实我还是不会
//几号，回溯中间不能有return，的
//我想我这属于瞎总结啊，加油啊
