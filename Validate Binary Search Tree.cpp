class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSubTreeLess(root->left,root->val)&&isSubTreeGreat(root->right,root->val)&&
            isValidBST(root->left)&&isValidBST(root->right);
    }
    //不是左节点小于根节点，右节点大于根节点即可，而是左子树所有节点全部小于当前根节点。对右子树一样。
    //前面的两个函数是不断检测下面的节点的数值小于当前root顶点值。这能够保证下面的节点全部符合条件
    //然后通过下面两个函数判断下面左右子树节点
    bool isSubTreeLess(TreeNode* root,int val){
        if(root==NULL)
            return true;
        if(root->val<val){
            return isSubTreeLess(root->left,val)&&isSubTreeLess(root->right,val);
        }
        return false;
    }
    
    bool isSubTreeGreat(TreeNode* root,int val){
        if(root==NULL)
            return true;
        if(root->val>val){
            return isSubTreeGreat(root->left,val)&&isSubTreeGreat(root->right,val);
        }
        return false;
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
    	if (root == NULL)
    		return true;
    	if (!less(root->left, root->val) || !greater(root->right, root->val))
    		return false;
    	return isValidBST(root->left) && isValidBST(root->right);
    }
    
    bool less(TreeNode* root,int val) {
    	if (root == NULL)
    		return true;
    	if (root->val >= val)
    		return false;
    	return less(root->left, val) && less(root->right, val);
    }
    
    bool greater(TreeNode* root,int val) {
    	if (root == NULL)
    		return true;
    	if (root->val <= val)
    		return false;
    	return greater(root->left, val) && greater(root->right, val);
    }
};

//一举拿下啊，哈哈
//哈哈，基本没问题了，我自己的方法，竟然成功啦
/*
    class Solution2 {
    public:
        int ok=true,first=true;
        bool isValidBST(TreeNode* root) {
            int prev;
            travel(root,prev);
            return ok;
        }
    
        void travel(TreeNode* root,int &prev){
            if(root==NULL)  return;
            if(root->left)  travel(root->left,prev);
            
            int mid=root->val;
            if(!first){
                if(mid<=prev)   ok=false;
                prev=mid;//mid 成为过去式
            }else{
                prev=mid;
                first=false;
            }
            
            if(root->right) travel(root->right,prev);
        }
    };
    
    class Solution3 {
    public:
        bool isValidBST(TreeNode* root){
            if(root==NULL||(root->left==NULL&&root->right==NULL))   return true;
            
            stack<TreeNode*>st;
            int prev=INT_MIN;
            bool first=true;
            
            while(!st.empty()||root!=NULL){
                if(root!=NULL){
                    st.push(root);
                    root=root->left;
                }else{
                    root=st.top();st.pop();
                    if(first||root->val>prev){
                        first=false;
                        prev=root->val;
                    }else{
                        return false;
                    }
                    root=root->right;
                }
            }
            
            return true;
        }
    };
    
    class Solution4 {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        if(root->left) {
            TreeNode* l = root->left;
            while(l){
                if(l->val >= root->val) return false;
                l = l->right;//为什么指向右边，这是因为，在每一次最下面递归调用函数的时候，都已经比较了一次当前
                             //节点与root值得大小，下面同理。
            }
        }

        if(root->right){
            TreeNode* r = root->right;
            while(r) {
                if(r->val <= root->val) return false;
                r = r->left;
            }
        }

        return isValidBST(root->left)&&isValidBST(root->right);
    }
};
*/
