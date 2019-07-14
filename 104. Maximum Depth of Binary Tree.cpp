 //本质上方法一样，只是通过实践竟然不同

class Solution2 {
public:
    int count=1;
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        //int left=maxDepth(root->left);
        //int right=maxDepth(root->right);
        return max(maxDepth(root->left)+1,maxDepth(root->right)+1);
    }
};
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
