/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if(head==NULL||head->next==NULL)
			return head;
		ListNode *slow=head,*fast=head;
		//slow指向head，所以推理来看head应该存储数据
		while(fast->next!=NULL&&fast->next->next!=NULL){
			fast=fast->next->next;
			slow=slow->next;
		}

		ListNode *head1=head;
		ListNode *head2=slow->next;
		slow->next=NULL;

		//分治法
		head1=sortList(head1);
		head2=sortList(head2);

		return merge(head1,head2);
	}

	ListNode *merge(ListNode *lh,ListNode *rh){
		ListNode *temp=new ListNode(0);
		ListNode *p=temp;

		while (lh!=NULL&&rh!=NULL){
			if (lh->val<=rh->val){
				p->next=lh;
				lh=lh->next;
			}
			else{
				p->next=rh;
				rh=rh->next;
			}
			//这个时候第一轮循环下来  p->rh  ，需要使得p指向下一个
			p=p->next;
		}
		//检测有没有剩余
		if (lh!=NULL){
			p->next=lh;
		}
		else{
			p->next=rh;
		}

		p=temp->next;//p指向temp->next
		temp->next=NULL;
		delete temp;

		return p;
	}
};
