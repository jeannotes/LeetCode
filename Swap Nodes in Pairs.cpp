class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *dummy=new ListNode(0),*tail=dummy;
        
        while(head!=NULL&&head->next!=NULL){
            ListNode *tmp=head->next;
            head->next=tmp->next;
            tail->next=tmp;
            tmp->next=head;
            
            tail=head;head=tail->next;
        }
        head=dummy->next;
        delete dummy;
        return head;
    }
};
