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
//注意引用啊，不然就会出错，
//这里简单介绍如何解题，假设此时只有 0，两个1,0 必然指向null，head=head->next 就是刚刚的1,0 
//以此解题
