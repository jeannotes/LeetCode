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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)  return true;
        return isSymmetricHelper(root->left,root->right);
    }
    
    bool isSymmetricHelper(TreeNode *s1,TreeNode *s2){
        if(s1==NULL)
            return s2==NULL;
        if(s2==NULL||s1->val!=s2->val)
            return false;
        return  isSymmetricHelper(s1->left,s2->right) &&  isSymmetricHelper(s1->right,s2->left);
    }
};
