class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)  return true;
        
        int left=treeDepth(root->left);
        int right=treeDepth(root->right);
        
        if(abs(left-right)>1)   return false;
        
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    
    int treeDepth(TreeNode* root){
        if(root==NULL)  return 0;
        
        int left=1,right=1;
        left+=treeDepth(root->left);
        right+=treeDepth(root->right);
        
        return max(left,right);
    }
};
//树的类型的题目做的多了，不过，链表、树的题目要多做
//还是不会,一次通过，是啊，好多不如意的，但是还是要加油
//一次通过
//  root==NULL  今天连续在这个地方出错两次
