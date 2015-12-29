class Solution{
public:
	ListNode *deleteDuplicates(ListNode *head){
	//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
		if (head==NULL||head->next==NULL)
			return head;
		ListNode *dummy=new ListNode(0);
		dummy->next=head;
		ListNode *p=dummy;//避免我的前面程序在一开头判断是否有连续相同数字

		while (p->next!=NULL&&p->next->next!=NULL){
			//这样子，出现[1 1]就不会出现问题，实在是厉害。
			if (p->next->val==p->next->next->val){
				int v=p->next->val;
				while (p->next!=NULL&&p->next->val==v){
					ListNode *tmp=p->next;
					p->next=tmp->next;
					delete tmp;
				}//既然有相等值，那就记录第一个，后面一直判断

			}
			else{
				p=p->next;
			}
		}
		head=dummy->next;
		delete dummy;
		return head;
	}
};
