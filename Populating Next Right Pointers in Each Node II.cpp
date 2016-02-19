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
    void connect(TreeLinkNode *root) {
        TreeLinkNode *dummy=new TreeLinkNode(0);
        
        if(root==NULL)  return;
        
        while(root!=NULL){
            TreeLinkNode *tail=dummy;
            while(root!=NULL){
                if(root->left){
                    tail->next=root->left;
                    tail=tail->next;
                }
                if(root->right){
                    tail->next=root->right;
                    tail=tail->next;
                }
                root=root->next;
            }
            root=dummy->next;
            dummy->next=NULL;//如果没有这句话，那么dummy只是上面那一层的
        }
        delete dummy;
    }
};
//由于有next，所以可以使得dummy作为每一层的开头，策略类似于刚刚的，从左到右
