class Solution1 {
public:
    int sum=0;
    int sumNumbers(TreeNode* root) {
        int result=0;
        if(root==NULL){
            return 0;
        }
        dfs(root,root->val);
        return sum;
    }
    
    int dfs(TreeNode *root,int num){
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

class Solution2 {
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL) return 0;
        return sumHelper(root, 0);
    }
    
    int sumHelper(TreeNode *root, int sum) {//这里sum代表还没有到达之前从顶端到这里的sum值
        if (root == NULL) return 0;
        
        sum = sum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            return sum;
        }
        
        return sumHelper(root->left, sum) + sumHelper(root->right, sum);
    }
};
//好题目啊，不会啊
// 还是不会啊，不会
