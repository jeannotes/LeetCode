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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        maxPath( root,res);
        
        return res;
    }
    
    int maxPath(TreeNode *root,int &res){
        if(root==NULL)  return 0;
        //res代表当前最大值
        
        int left=maxPath(root->left,res);
        int right=maxPath(root->right,res);
        
        int tem=root->val+(left>0?left:0)+(right>0?right:0);
        res=tem>res?tem:res;
        //首先tem的功能就是左边加上节点加上右节点，更新整体的res值。
        //至于函数返回值，返回的应该是加上本节点与左右子树的最大值。
        //我们定义函数返回值为根节点到左右两边，只能是单边的最大值，res是一直在更新的
        //函数的意思是从本节点到某一个节点的最大值，一定有本节点。
        return root->val+max(left,max(right,0));
    }
};
