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
//https://leetcode.com/problems/path-sum/
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){//主要是为了判断顶点
            return false;
        }
        
        if(root->left==NULL&&root->right==NULL){
            return root->val==sum;
        }
        //这边相当于经历了第一层
        //开始经历第二层
        if(root->left){
            root->left->val+=root->val;
            //这个时候递归调用这个函数
            if(hasPathSum(root->left,sum)){
                return true;
            }//不能写 return hasPathSum(root->left, sum) 的原因是，我左边不能通过，右边可能存在呢。
             //有更好，没有算了
        }
        
        if(root->right){
            root->right->val+=root->val;
            if(hasPathSum(root->right,sum)){
                return true;
            }
        }
        
        return false;//无论上面怎么调用，都没用，返回false
    }
};
//虽然还不太会，但是比以前熟悉多了
