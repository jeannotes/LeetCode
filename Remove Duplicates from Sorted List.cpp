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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == NULL||head->next==NULL)
    		return head;
    	ListNode* dummy = new ListNode(0),*tail=dummy;
    	dummy->next = head;
    	while (head&&head->next){
    		if (head->val == head->next->val) {
    			int tem1 = head->val;
    			ListNode* tem2 = head->next;
    			while (tem2&&tem2->val==tem1){
    				tem2 = tem2->next;//1 222 3
    			}
    			head->next = tem2;
    		}
    		head = head->next;
    	}
    	return dummy->next;
    }
};
//不太会啦
//一次通过哈，加油，第一种方法更好
