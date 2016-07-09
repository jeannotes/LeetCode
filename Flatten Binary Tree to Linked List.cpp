class Solution1 {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
    	if (root == NULL)
    		return;
    	flatten(root->right);
    	flatten(root->left);
    	root->right = prev;
    	root->left = NULL;
    	prev = root;
    }
};

//第一题没问题，第二题还不会啊
//  递归的力量相当强大啊，其实他们的解法本质上是一样的。
void flatten(TreeNode* root) {
	if (root == NULL)
		return;
	while (root){
		if (root->left) {//Find current node's prenode that links to current node's right subtree
			TreeNode *pre = root->left;
			while (pre->right){
				pre = pre->right;
			}
			pre->right = root->right;
			//Use current node's left subtree to replace its right subtree(original right 
            //subtree is already linked by current node's prenode
			root->right = root->left;
			root->left = NULL;
		}
		root = root->right;
	}
}
// 还是不会啊
