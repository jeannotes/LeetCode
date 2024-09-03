class Solution {
public:
    Node* connect(Node* root) {
        Node *dummy=new Node(0), *dummy2=root;
        
        if(root==NULL)  return root;
        
        while(root!=NULL){
            Node *tail=dummy;
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
        return dummy2;
    }
};
//由于有next，所以可以使得dummy作为每一层的开头，策略类似于刚刚的，从左到右
//这里不需把每一层最后next指向null，因为实际上已经指向null ， 另外 ， 本程序实际上 虚拟化 root->left 指向 root->right  ，
//并不是root->left主动指向 root->right ， 而是通过设置tail 来操作的,，感觉还不错，没怎么忘，还是多练习基础啊
// 一次AC啊  不会了啊
