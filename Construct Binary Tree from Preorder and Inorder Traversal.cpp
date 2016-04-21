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
		return constructHelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
	}

	TreeNode* constructHelper(vector<int>& preorder, int preStart,int preEnd,
				vector<int>& inorder,int inStart,int inEnd){
		if (preStart>preEnd||inStart>inEnd){
			return NULL;
		}

		int val=preorder[preStart];
		int k=0;
		for (int i=inStart;i<=inEnd;i++){
			if (inorder[i]==val){
				k=i;break;
			}
		}
		//12453687
		//42516837
		TreeNode* p=new TreeNode(val);
		p->left=constructHelper(preorder,preStart+1,k-inStart+preStart,inorder,inStart,k-1);
		p->right=constructHelper(preorder,k-inStart+preStart+1,preEnd,inorder,k+1,inEnd);
		return p;
	}
};
// 这个是好题目，在最后递归地方从哪里开始那边，start是哪个，end是哪个，要分清楚哦
