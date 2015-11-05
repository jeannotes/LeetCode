class Solution {
//https://leetcode.com/problems/reverse-nodes-in-k-group/
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k<=0||head==NULL)    return head;
        ListNode *dummy=new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
    
        while(p){
            p->next = reverseList(p->next, k);
            for(int i=0; p && i<k; i++){
                p = p->next;
            }
        }
    
        return dummy->next;
}

    ListNode *reverseList(ListNode *head, int k){
        ListNode *pEnd=head;
        while(pEnd&&k>0){
            pEnd=pEnd->next;
            k--;
        }
        if(k>0) return head;
        
        ListNode *pHead=pEnd,*p=head;
        while(p!=pEnd){
            ListNode *q=p->next;
            p->next=pHead;//有一个好处就是pHead指向空的，自动的了，不想之前需要考虑这个问题，直接从头部指向最后一个
            pHead=p;
            p=q;
        }
        return pHead;//是连续的，后面的不会断开。
    } 
};
