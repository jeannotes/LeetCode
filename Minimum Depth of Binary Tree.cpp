 //https://leetcode.com/problems/minimum-depth-of-binary-tree/
class Solution1 {
public:
    int minDepth(TreeNode* root) {
    	if (root == NULL)
    		return 0;
    	if (root->left == NULL)
    		return 1+minDepth(root->right);
    	if (root->right == NULL)
    		return 1+minDepth(root->left);
    	int i = minDepth(root->left), j = minDepth(root->right);
    	return 1 + min(i, j);
    }
};
//本题要注意的是，不能写成左子树空，就返回0，这时候就要加1，早返回右边的数值，详见代码
//这里很重要
// 还是不会啊
// 本题不能掉以轻心，要记住上面的总结
class Solution2 {
public:
    int minDepth(TreeNode* root) {
    	return BFS(root);
    }
    
    int BFS(TreeNode* root) {
        int curDepth =0;
    	if (root == NULL)
    		return 0;
    	queue<pair<TreeNode*, int>>q;
    	q.push(make_pair(root, 1));
    	while (!q.empty()){
    		TreeNode* curNode = q.front().first; 
    		curDepth = q.front().second;
    		q.pop();
    		if (curNode->left == NULL&&curNode->right == NULL)
    		    break;
    		if (curNode->left)
    			q.push(make_pair(curNode->left, curDepth + 1));
    		if (curNode->right)
    			q.push(make_pair(curNode->right, curDepth + 1));
    	}
    	return curDepth;
    }
};
//不会啊,就用第一个方法啊，加油,/细枝末节的错误啊,递归容易出错啊，递归没问题啊，非递归不会了
// 看来还是没有真正理解啊，稍微会了一点，以后继续啊
// 一丢丢会了
