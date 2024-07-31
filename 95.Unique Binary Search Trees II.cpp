class Solution1 {
public:
    vector<TreeNode*>res;
    vector<TreeNode*> generateTrees(int n) {
    	if (n == 0)
    		return res;
    	vector<vector<TreeNode*> >dp(n + 1);
    	dp[0].push_back(NULL);
    	dp[1].push_back(new TreeNode(1));
    
    	for (int i = 2; i <= n;i++) {
    		for (int j = 1; j <= i;j++) {
    			for (int k = 0; k < dp[j - 1].size();k++) {
    				for (int l = 0; l < dp[i - j].size();l++) {
    					dp[i].push_back(new TreeNode(j));//123 4 56
    					dp[i].back()->left = dp[j - 1][k];
    					traverse_copy(dp[i-j][l], dp[i].back()->right, j);
    				}
    			}
    		}
    	}
    	return dp[n];
    }
    
    void traverse_copy(TreeNode* &root, TreeNode* &dst, int val) {
    	if (root == NULL)
    		return;
    	dst = new TreeNode(root->val + val);
    	if (root->left)
    		traverse_copy(root->left, dst->left, val);
    	if (root->right)
    		traverse_copy(root->right, dst->right, val);
    }
};
//比之前好多了
/*
if (root == NULL)
    		return;  忘记这句话了
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;
		if (n==0){
			return res;
		}
		return treeHelper(1,n);
	}

	vector<TreeNode*> treeHelper(int start,int end){
		if (start>end){
			return vector<TreeNode*> (1,NULL);
		}
		vector<TreeNode*> result;
		for (int i=start;i<=end;i++){
			vector<TreeNode*> left,right;
			left=treeHelper(start,i-1);
			right=treeHelper(i+1,end);
			for (int m=0;m<left.size();m++){
				for (int n=0;n<right.size();n++){
					result.push_back(new TreeNode(i));
					result.back()->left=left[m];result.back()->right=right[n];
				}
			}
			
		}
		return result;
	}
};
//好题目
//   vector<TreeNode*> dp(NULL);  这个地方  写成vector<TreeNode*> dp(1，NULL);就会出错
//来总结一下 ：第一个方法是这样，vector<TreeNode*> dp(1，NULL);最后返回 “[[]]”，因为中间是一个null
//而第二个方法是 : 如果写成return vector<TreeNode*> (NULL);这个没有大小，后面left[i]反而没有意义了
// 递归不会啊
