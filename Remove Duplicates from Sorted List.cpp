class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		if (head==NULL){
			return head;
		}
		ListNode* p=head;
		while (p&&p->next){
			if (p->val==p->next->val){
				p->next=p->next->next;
			}else
				p=p->next;//1 2 2 3
		}
		return head;
	}
};
//加油加油，还有很多需要努力
//一次成功
