class Solution {
//https://leetcode.com/problems/reverse-nodes-in-k-group/
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode(0);dummy->next=head;
        ListNode *p=dummy;
        
        while(p){
            p->next=reverseList(p->next,k);
            for(int i=1;p&&i<=k;i++){
                p=p->next;//不能漏掉p这个条件
            }
        }
        return dummy->next;
    }
    
    ListNode* reverseList(ListNode* head,int k){
        if(k<=0)    return head;
        ListNode* pEnd=head; 
        while(pEnd&&k--){
            pEnd=pEnd->next;
        }
        if(k>0) return head;
        ListNode *pHead=pEnd,*p=head;
        while(p!=pEnd){
            ListNode *q=p->next;//有一个好处就是pHead指向空的，自动的了，不想之前需要考虑这个问题，直接从头部指向最后一个
            p->next=pHead;
            pHead=p;
            p=q;//从后面往前
        }
        return pHead;//连续，后面不断开
        //比如说1 2 3 4 k=2
        //1->3  2->1
    }
};
