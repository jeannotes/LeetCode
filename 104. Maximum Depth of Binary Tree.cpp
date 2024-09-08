 //本质上方法一样，只是通过实践竟然不同

int maxDepth(TreeNode* root) {
    if(!root) return 0;
    if(!root->left) return 1+maxDepth(root->right);
    if(!root->right) return 1+maxDepth(root->left);

    return 1+std::max(maxDepth(root->left), maxDepth(root->right));
}
class Solution {
public:
    int res = 0;
    int maxDepth(TreeNode* root) {
        searchMaxPath(root, 0);
        return res;
    }
     
    void searchMaxPath(TreeNode *root, int cur){
        if(!root) {
            res =0;
            return;
        }
        cur++;
        if(!root->left && !root->right){
            res = max(res, cur);
            return;
        }
        if(root->left) searchMaxPath( root->left, cur);
        if(root->right) searchMaxPath( root->right, cur);
    }
};
