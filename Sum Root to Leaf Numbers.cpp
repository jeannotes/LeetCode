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
        }//  这不不能直接  dfs(root->left,10*num+root->left->val); 的原因就是 root->left可能为空，那么
        //root->left->val可能没有意义
        if(root->right!=NULL){
            dfs(root->right,10*num+root->right->val);
        }
        
    }
};
//好题目啊，本题似乎是找不到能够返回的，其实，对于那种返回的值传递，不太能够理解啊。
// 意思懂了，但是粗心啊  10* 都没加上
