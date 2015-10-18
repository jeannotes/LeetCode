/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode *> >dp(n+1);
        if(n<1){
            dp[0].push_back(NULL);
            return dp[0];
        }
        
        dp[0].push_back(NULL);dp[1].push_back(new TreeNode(1));//数字1没有其他节点
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){//单独空的节点不考虑了，所以从1开始
                for(int k=0;k<dp[j-1].size();k++){
                    for(int w=0;w<dp[i-j].size();w++){
                        //dp[i]  push 的次数就是k*w的结果，所以每次都是push i一次
                        //然后他的back的left指向dp[j]的
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
        if(root==NULL){
            return;
        }
        dst=new TreeNode(root->val+val);
        if(root->left){
            traverse_add_copy(root->left,dst->left,val);
        }
        if(root->right){
            traverse_add_copy(root->right,dst->right,val);
        }
    }
};


class Solution2 {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *>result;
        helper(1,n,result);
        return result;
    }
    
    void helper(int start,int end,vector<TreeNode *> &result){
        if(start>end){
            result.push_back(NULL);
            return;//左子树必须小于根节点，所以压入NULL
        }
        
        for(int i=start;i<=end;i++){
            vector<TreeNode *> tmpLeft,tmpRight;
            helper(start,i-1,tmpLeft);
            helper(i+1,end,tmpRight);
            //生成左右子树，从节点start到i-1，还有就是i+1到end
            for(int k=0;k<tmpLeft.size();k++){
                for(int j=0;j<tmpRight.size();j++){
                    TreeNode *root=new TreeNode(i);
                    //本质上是中序遍历
                    root->left=tmpLeft[k];
                    root->right=tmpRight[j];//左边选择比自己小的，右边选择比自己大的
                    result.push_back(root);
                }
            }
        }
    }
};
