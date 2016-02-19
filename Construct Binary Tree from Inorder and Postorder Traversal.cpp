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
		return constructHelper(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
	}
	TreeNode* constructHelper(vector<int>& postorder,int postStart,int postEnd,vector<int>& inorder,int inStart,int inEnd){
		
		if (postStart>postEnd||inStart>inEnd){
			return NULL;
		}
		int val=postorder[postEnd];
		int k=0;
		for (int i=inStart;i<=inEnd;i++){
			if (inorder[i]==val){
				k=i;
				break;
			}
		}
		//45286731 后
		//42516837 中
		TreeNode* p=new TreeNode(val);
		p->left=constructHelper(postorder,postStart,postStart+k-inStart-1,inorder,inStart,k-1);
		p->right=constructHelper(postorder,postStart+k-inStart,postEnd-1,inorder,k+1,inEnd);
		return p;
	}
};//对照数字，清清楚楚
