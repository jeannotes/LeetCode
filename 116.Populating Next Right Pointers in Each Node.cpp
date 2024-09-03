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
//值得庆祝的一天，递归写出来了

//还是有许多问题啊

//第二种方法：if (root->right&&root->next) 按照道理不写左边的root->right没事，
//因为第二句root->left存在，那么root->right一定存在
//但是到最底层，最左边的时候，root->next是存在的，只是当前的root->right->next不存在
// 感觉还可以啊
