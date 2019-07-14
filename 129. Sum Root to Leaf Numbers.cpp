class Solution {
public:
    int res = 0;
    int sumNumbers(TreeNode* root) {
        if(!root){return res;}
        sumNumbersHelper( root, root->val);
        
        return res;
    }
    void sumNumbersHelper(TreeNode* root, int val) {
        if(!root){return;}
        if(!root->left && !root->right){
            res += val;
        }
        if(root->left) sumNumbersHelper(root->left, val*10+root->left->val);
        if(root->right) sumNumbersHelper(root->right, val*10+root->right->val);
    }
};
//好题目啊，本题似乎是找不到能够返回的，其实，对于那种返回的值传递，不太能够理解啊。
// 意思懂了，但是粗心啊  10* 都没加上，基本没问题，可以的，加油啊，虽然刷题没什么大用
