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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int posStart=0,preEnd=postorder.size()-1;
        int inStart=0,inEnd=inorder.size()-1;
        
        return constructHelper(postorder,posStart,preEnd,
                inorder, inStart, inEnd);
    }
    
    TreeNode* constructHelper(vector<int>&postorder,int posStart,int posEnd,
                vector<int>&inorder,int inStart,int inEnd){
        if(posStart>posEnd||inStart>inEnd)  return NULL;
        
        int val=postorder[posEnd];
        TreeNode*p =new TreeNode(val);
        int k=0;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==val){
                k=i;break;//第k个
            } 
        }
        
        p->left= constructHelper(postorder,posStart,posStart+k-inStart-1,inorder, inStart,k-1);//k之前
                //k-start  考虑这种情况，在找到右子树的左子树的时候
                //k在右边，inStart也在右边，此时需要找的是左边的个数，
                //k-inStart 就解决了这个问题
        p->right=constructHelper(postorder,posStart+k-inStart , posEnd-1,inorder,k+1, inEnd); 
        return p;        
    }
};
