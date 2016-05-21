class Solution {
public:
    void connect(TreeLinkNode *root) {
		if (root==NULL){
			return;
		}
		if (root->left){
			root->left->next=root->right;
		}
		if (root->right&&root->next){
			root->right->next=root->next->left;
		}
		connect(root->left);connect(root->right);
	}
};
//值得庆祝的一天，递归写出来了

//还是有许多问题啊

//第二种方法：if (root->right&&root->next) 按照道理不写左边的root->right没事，
//因为第二句root->left存在，那么root->right一定存在
//但是到最底层，最左边的时候，root->next是存在的，只是当前的root->right->next不存在
// ，递归可以的，没有问题
