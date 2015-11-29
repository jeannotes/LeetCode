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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart=0,preEnd=preorder.size()-1;
        int inStart=0,inEnd=inorder.size()-1;
        
        return constructHelper(preorder,preStart,preEnd,
                inorder, inStart,inEnd);
    }
    
    TreeNode* constructHelper(vector<int>&preorder,int preStart,int preEnd,
                vector<int>&inorder,int inStart,int inEnd){
        if(preStart>preEnd||inStart>inEnd)  return NULL;
        
        int val=preorder[preStart];
        TreeNode*p =new TreeNode(val);
        int k=0;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==val){
                k=i;break;
            } 
        }
        
        p->left= constructHelper(preorder,preStart+1,preStart+(k-inStart),
                inorder, inStart,k-1);//k之前
                //k-start  考虑这种情况，在找到右子树的左子树的时候
                //k在右边，inStart也在右边，此时需要找的是左边的个数，
                //k-inStart 就解决了这个问题
        p->right=constructHelper(preorder,preStart+(k-inStart)+1, preEnd,
                inorder,k+1, inEnd); 
        return p;        
    } 
};
