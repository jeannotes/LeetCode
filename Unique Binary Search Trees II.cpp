class Solution1 {
public://https://leetcode.com/problems/unique-binary-search-trees-ii/
    vector<TreeNode*> generateTrees(int n) {
        if(n<1){
            vector<TreeNode*> dp(NULL);
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
        if(root->left){
            traverse_add_copy(root->left,dst->left,val);
        }
        if(root->right){
            traverse_add_copy(root->right,dst->right,val);
        }
    }
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n==0)  return result;
        return help(1, n);
    }

    vector<TreeNode*> help(int s, int e){
        if(s>e)   return vector<TreeNode*>(1, NULL);
        vector<TreeNode*> result;
        for(int i=s; i<=e; i++){
            vector<TreeNode*> left, right;
            left=help(s, i-1);
            right=help(i+1, e);
            for(int m=0; m<left.size(); m++){
                for(int n=0; n<right.size(); n++){
                    TreeNode* root=new TreeNode(i);
                    root->left=left[m];
                    root->right=right[n];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
