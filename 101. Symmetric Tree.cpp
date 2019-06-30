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
//好题目
//用vs是很方面的
//好啊，一次通过
// 哈哈，直接用之前一题的答案，稍微改装
