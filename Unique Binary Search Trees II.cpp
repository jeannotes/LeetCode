class Solution1 {
public://https://leetcode.com/problems/unique-binary-search-trees-ii/
    vector<TreeNode*> generateTrees(int n) {
        if(n<1){
            vector<TreeNode*> dp(NULL);//vector<TreeNode*> dp; 写成这个也是可以的
            return dp;
        }
        vector<vector<TreeNode*> >dp(n+1);
        dp[0].push_back(NULL);
        dp[1].push_back(new TreeNode(1));
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                for(int k=0;k<dp[j-1].size();k++){
                    for(int w=0;w<dp[i-j].size();w++){
                        dp[i].push_back(new TreeNode(j));
                        dp[i].back()->left=dp[j-1][k];
                        traverse_add_copy(dp[i-j][w],dp[i].back()->right,j);
                    }
                }
            }
        }
        return dp[n];
    }

    void traverse_add_copy(TreeNode *&root,TreeNode *&dst,int val){
        if(root==NULL)  return;
        dst=new TreeNode(root->val+val);
        
        traverse_add_copy(root->left,dst->left,val);
        traverse_add_copy(root->right,dst->right,val);
    }
};
//比之前好多了
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
//还是要多加练习的
// 学习如逆水行舟啊，不进则退
//还是不会啊，还是不很熟啊
