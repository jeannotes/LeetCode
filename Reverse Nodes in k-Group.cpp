    ListNode* reverseKGroup(ListNode* head, int k) {
    	if (head==NULL||k>lengthGet(head))
    		return head;
    	ListNode* dummy=new ListNode(0),*p=dummy;dummy->next=head;
    	while (p){
    		p->next=reverse_list(p->next,k);
    		for (int i=1;i<=k&&p;i++){
    			p=p->next;
    		}
    	}
    	return dummy->next;
    }
    
    ListNode* reverse_list(ListNode * &head,int k){
    	if (head==NULL||k==0||k>lengthGet(head))
    		return head;
    	
    	ListNode* dummy=new ListNode(0),* fast=head;dummy->next=head;
    	// 0 123 4  // 0 213 4 // 0 321 4 
    	
    	//ListNode* fast=head;
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
    //很明显，我的方法更好
