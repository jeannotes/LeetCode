class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(0),*tail=dummy;
        //merge k sorted lists
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<l2->val){
                tail->next=l1;
                l1=l1->next;
            }else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        //检测还有没有剩余
        if(l1)
            tail->next=l1;
        if(l2)
            tail->next=l2;
            
        ListNode *head=dummy->next;
        delete dummy;
        return head;
    }
};
//  本次直接在if里面return 导致两者为空的情况没有考虑
//一次通过
