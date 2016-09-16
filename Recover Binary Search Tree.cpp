class Solution {
public:
    void recoverTreeHelper(TreeNode *root){
        if(root==NULL)  return;
        recoverTreeHelper(root->left);
        
        if(prev){
            if(prev->val>root->val){
                if(n1==NULL)
                    n1=prev;
                n2=root;
            }
        }
        prev=root;//可以这样想，前面判断之后，就是继续下一次判断，这个时候root作为下一次的prev了。
        recoverTreeHelper(root->right);
    }
    
    void recoverTree(TreeNode *root) {
        recoverTreeHelper(root);
        if(n1&&n2)
            swap(n1->val,n2->val);
    }
private:
    TreeNode *n1=NULL,*n2=NULL,*prev=NULL;
};

//中序遍历，此时是有序的， 还行  就是 就是容易 就是容易粗心 
class Solution2 {
public:
    TreeNode*n1=NULL,*n2=NULL,*prev=NULL;
    void recoverTree(TreeNode* root) {
        TreeNode *n1=NULL,*n2=NULL,*prev=NULL;
        stack<TreeNode*>stk;
        while(root!=NULL||!stk.empty()){
            if(root!=NULL){
                stk.push(root);
                root=root->left;
            }else{
                root=stk.top();stk.pop();
                if(prev!=NULL){
                    if(prev->val>root->val){
                        if(n1==NULL)
                            n1=prev;
                        n2=root;
                    }
                }
                prev=root;
                root=root->right;
            }
        }
        swap(n1->val,n2->val);
    }
    
};
//这是一道好题目，需要慢慢消化
//还有些许小问题
//还是不会啊，感觉还行，递归这次是自己思考的，虽然没能一次AC
//  感觉稍微理解一点递归的了，尤其是dfs啊
