 //本质上方法一样，只是通过实践竟然不同
class Solution1 {
//https://leetcode.com/problems/maximum-depth-of-binary-tree/
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){
            return 1;
        }
        
        int left=0;
        if(root->left){
            left=maxDepth(root->left)+1;
        }
        
        int right=0;
        if(root->right){
            right=maxDepth(root->right)+1;
        }
        
        return max(left,right);
    }
};


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
