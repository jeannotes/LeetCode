class Solution {
public:
//https://leetcode.com/problems/partition-list/
	ListNode* partition(ListNode* head, int x) {
		if (head==NULL||head->next==NULL){
			return head;
		}

		ListNode *left=new ListNode(-1),*right=new ListNode(-1);
		ListNode *leftTail=left,*rightTail=right;

		while (head!=NULL){
			if (head->val<x){
				leftTail->next=head;
				head=head->next;
				leftTail=leftTail->next;
				leftTail->next=NULL;
			}else{
				rightTail->next=head;
				head=head->next;
				rightTail=rightTail->next;
			}
		}
		right=right->next;
		leftTail->next=right;
		rightTail->next=NULL;
		return left->next;

	}
};
