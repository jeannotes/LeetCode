/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root){
        if(root==NULL)  return ;
        
        while(root&&root->left){
            TreeLinkNode *tmp=root->left;
            while(root){
                root->left->next=root->right;
                if(root->next){
                    root->right->next=root->next->left;
                }
                root=root->next;//好题目啊，因为这个时候是完美的二叉树，所以可以这样写
            }
            root=tmp;
        }
    }
};

class Solution2 {
public:
    void connect(TreeLinkNode *root) {
		if (root==NULL){
			return;
		}
		if (root->left&&root->right){
			root->left->next=root->right;
		}
		if (root->right&&root->next){
			root->right->next=root->next->left;
		}
		connect(root->left);connect(root->right);
	}
};
