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
//http://blog.csdn.net/jsrgfjz/article/details/48696527
//https://leetcode.com/problems/binary-tree-postorder-traversal/
    vector<int> postorderTraversal1(TreeNode *root) {
    vector<int> result;
    vector<TreeNode*> stack;
    TreeNode *node=root;
    TreeNode *lastVisitNode=NULL;
    
    while(node!=NULL||stack.size()>0){
        if(node!=NULL){
            stack.push_back(node);
            node=node->left;
        }else{
            TreeNode *n=stack.back();
            if(n->right==NULL||lastVisitNode==n->right){
                //如果为空，访问根节点，如刚刚访问右节点，访问根节点。
                result.push_back(n->val);
                stack.pop_back();
                lastVisitNode=n;
            }
            else{
                //访问的左节点,没有关系，反正最后还是会转移到这个节点
                node=n->right;
            }
        }
    }
    return result;
}
};

class Solution2 {
public:
    vector<int> postorderTraversal2(TreeNode *root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
    
    void postorderHelper(TreeNode *root, vector<int> &result) {
        if (root == NULL) return;
        postorderHelper(root->left, result);
        postorderHelper(root->right, result);
        result.push_back(root->val);
    }
};
