class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
		if (head==NULL){
			return NULL;
		}
		ListNode* p=head;
		int len=0;
		while (p!=NULL){
			p=p->next;len++;
		}
		return buildhelper(0,len-1,head);
	}

	TreeNode* buildhelper(int start,int end,ListNode* &head){
		if (start>end||head==NULL){
			return NULL;
		}

		int mid=(start+end)/2;
		TreeNode* leftNode=buildhelper(start,mid-1,head);
		TreeNode* node=new TreeNode(head->val);
		node->left=leftNode;
		head=head->next;
		TreeNode* rightNode=buildhelper(mid+1,end,head);
		node->right=rightNode;
		return node;
	}
};
//还是有些不太理解
