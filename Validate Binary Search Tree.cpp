class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)  return true;
        
        return isSubTreeGreater(root->left,root->val)&&isSubTreeLess(root->right,root->val)
                &&isValidBST(root->left)&&isValidBST(root->right);
                //不是左节点小于根节点，右节点大于根节点即可，而是左子树所有节点全部小于当前根节点。对右子树一样。
                //前面的两个函数是不断检测下面的节点的数值小于当前root顶点值。这能够保证下面的节点全部符合条件
                //然后通过下面两个函数判断下面左右子树节点
    }
    
    bool isSubTreeGreater(TreeNode* root,int val){
        if(root==NULL)  return true;
        
        return root->val<val&&isSubTreeGreater(root->left,val)&&isSubTreeGreater( root->right,val);
    }
    
    bool isSubTreeLess(TreeNode* root,int val){
        if(root==NULL)  return true;
        
        return root->val>val&&isSubTreeLess(root->left,val)&&isSubTreeLess( root->right,val);
    }

};
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
