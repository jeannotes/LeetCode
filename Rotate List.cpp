class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||k==0)
            return head;
            
        int len=getLength(head);
        ListNode *last=head;
        while(last->next!=NULL)
            last=last->next;
        
        k=k%len;
        if(k==0)
            return head;
        
        ListNode *tmp=head;
        for(int i=1;i<len-k;i++){
            tmp=tmp->next;
        }
        
        last->next=head;
        head=tmp->next;
        tmp->next=NULL;
        return head;
    }
    
    int getLength(ListNode *head){
        if(head==NULL)
            return 0;
        else
            return 1+getLength(head->next);
    }
};
