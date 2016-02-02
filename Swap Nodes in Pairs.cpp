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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* dummy=new ListNode(0),*p=dummy;
        dummy->next=head;
        
        while(p){
            p->next=reversePairs(p->next);
            for(int i=1;p&&i<=2;i++)
                p=p->next;
        }
        return dummy->next;
    }
    ListNode* reversePairs(ListNode* head){
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* pEnd=head;
        int k=2;
        while(pEnd&&k--){
            pEnd=pEnd->next;
        }
        if(k>0)
            return head;
        ListNode* finalHead=pEnd;
        while(head!=pEnd){
            ListNode* tmp=head->next;
            head->next=finalHead;
            finalHead=head;
            head=tmp;
        }
        return finalHead;
    }
    
};
