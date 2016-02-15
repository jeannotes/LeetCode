class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* t=head;
        while(t->next!=NULL){
            if(t->val==t->next->val){
                ListNode* tmp=t->next;
                t->next=tmp->next;
                delete tmp;
            }else
                t=t->next;
        }
        return head;
    }
};
//加油加油，还有很多需要努力
