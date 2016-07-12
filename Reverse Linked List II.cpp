class Solution {
public:
    ListNode* reverse_list(ListNode * & head,int k){
    	if (head==NULL||k==0||k>lengthGet(head))
    		return head;
    	
    	ListNode* dummy=new ListNode(0),*p=head;dummy->next=head;
    	// 0 123 4  // 0 213 4 // 0 321 4 
    	
    	ListNode* fast=head;
    	while (--k){
    		ListNode* tem1=fast->next;
    		fast->next=fast->next->next;
    		tem1->next=dummy->next;
    		dummy->next=tem1;
    	}
    	return dummy->next;
    }
    
    int lengthGet(ListNode *head){
    	if (head==NULL)
    		return 0;
    	return 1+lengthGet(head->next);
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	ListNode* dummy=new ListNode(0),*p=dummy;dummy->next=head;
    	for (int i=1;i<m;i++){
    		p=p->next;
    	}
    	p->next=reverse_list(p->next,n-m+1);
    	return dummy->next;
    }
};
//好题目，要一直练习
//总算一下子写出来了
//没有记住开头的小问题，加油，要乐观
//一次通过啊，加油
//  链表的题目最近练得还行，今天出问题了，	tem1->next=dummy->next;  后边我写的是fast啊
