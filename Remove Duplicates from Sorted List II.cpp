class Solution{
public://不是连续出现两次，而是全部相同的删除
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
//链表的题目一定要加强，今年找工作啦，加油
// while (p->next!=NULL&&p->next->val==v)  这个大循环里面一定是  p->next!=NULL 放在最前面
//这次一次通过
//写一个我的版本
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == NULL || head->next == NULL)
    		return head;
    	ListNode* dummy = new ListNode(0), *tail = dummy;
    	dummy->next = head;
    	while (tail->next&&tail->next->next) {
    		if (tail->next->val == tail->next->next->val) {
    			int tem1 = tail->next->val;
    			ListNode* tem2 =tail->next->next;
    			while (tem2&&tem2->val == tem1) {
    				tem2 = tem2->next;//1 222 3
    			}
    			tail->next = tem2;
    		}else {
    			tail = tail->next;
    		}
    			
    	}
    	return dummy->next;
    }
//  一次通过咯，加油加油啊，没有一次AC啊
