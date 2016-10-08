class Solution
{
public:
	ListNode *sortList(ListNode *head){
		if (head==NULL||head->next==NULL){
			return head;
		}
		ListNode *slow=head,*fast=head;
		//假定head存放数据

		while (fast->next!=NULL&&fast->next->next!=NULL){
			fast=fast->next->next;
			slow=slow->next;
		}

		ListNode *head1=slow->next;
		ListNode *head2=head;
		slow->next=NULL;//slow指向null

		head1=sortList(head1);
		head2=sortList(head2);

		return merge(head1,head2);
	}

	ListNode *merge(ListNode *lh,ListNode *rh){
		ListNode *temp=new ListNode(0);
		ListNode *p=temp;

		while (lh!=NULL&&rh!=NULL){
			if (lh->val<rh->val){
				p->next=lh;
				lh=lh->next;
			}
			else{
				p->next=rh;
				rh=rh->next;
			}
			p=p->next;
			//这个时候第一轮循环下来  p->rh  ，需要使得p指向下一个
		}

		//检测有没有剩余
		if (lh!=NULL){
			p->next=lh;
		}else{
			p->next=rh;
		}
		//p现在到了后面，当然也有可能最后面  没想到一个链表也能递归啊
		p=temp->next;
		temp->next=NULL;//让temp指向null
		delete temp;

		return p;
	}
// 快慢指针的方法非常好啊
};
