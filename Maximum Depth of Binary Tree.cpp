 //本质上方法一样，只是通过实践竟然不同

class Solution2 {
public:
    int count=1;
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        //int left=maxDepth(root->left);
        //int right=maxDepth(root->right);
        return max(maxDepth(root->left)+1,maxDepth(root->right)+1);
    }
};
//两题是类似的，都可以使用前面两种类型解决
class Solution3 {
public:
   int maxDepth(TreeNode* root) {
		if (root==NULL){
			return 0;
		}
		int left=getLength(root->left)+1;
		int right=getLength(root->right)+1;
		return max(left,right);
	}
	int getLength(TreeNode* root){
		if (root==NULL){
			return 0;
		}
		int left=getLength(root->left)+1;
		int right=getLength(root->right)+1;
		return max(left,right);
	}
};
// 不 会a
