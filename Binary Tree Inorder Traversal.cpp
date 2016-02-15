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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st;
        while(root!=NULL||!st.empty()){
            while(root!=NULL){
                st.push(root);root=root->left;
            }
            root=st.top();st.pop();
            res.push_back(root->val);
            root=root->right;
        }
        return res;
    }
};
//碰到一个非常好的方法
