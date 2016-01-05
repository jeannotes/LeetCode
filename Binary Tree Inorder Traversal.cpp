//https://leetcode.com/problems/binary-tree-inorder-traversal/
class Solution1 {
public:
    vector<int> inorderTraversal1(TreeNode* root){
        vector<int> result;
        inorderHelper(root,result);
        return result;
    }
    
    void inorderHelper(TreeNode *root,vector<int> &result){
        if(root==NULL) return;
        inorderHelper(root->left,result);
        result.push_back(root->val);
        inorderHelper(root->right,result);
    }
};


class Solution2 {
public:
    vector<int> inorderTraversal2(TreeNode* root){
        stack<TreeNode *>st;
        vector<int> result;
        
        while(!(root==NULL&&st.empty())){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }else{
                root=st.top();st.pop();
                result.push_back(root->val);
                root=root->right;
            }//这个时候while循环是不对的，如果只有左子树，就不能出结果。因为有堆栈，可以判断是否为空。
        }
        return result;
    }
    
};
