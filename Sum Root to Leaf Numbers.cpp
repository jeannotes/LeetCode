class Solution {
public:
    int sum=0;
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        dfs(root,root->val);
        return sum;
    }
    
    void dfs(TreeNode *root,int num){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            sum+=num;//这个时候是总和
        }
        if(root->left!=NULL){
            dfs(root->left,10*num+root->left->val);
        }
        if(root->right!=NULL){
            dfs(root->right,10*num+root->right->val);
        }
        
    }
};
//好题目啊，本题似乎是找不到能够返回的，其实，对于那种返回的值传递，不太能够理解啊。
// 用这个dfs void类型的，能够更好的理解。
