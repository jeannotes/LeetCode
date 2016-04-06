/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int len=getLength(head);
        ListNode *last=head;
        while(last->next!=NULL)//it should be last->next
            last=last->next;
        
        k=k%len;
        if(k==0)
            return head;
        ListNode *tmp=head;
        for(int i=1;i<len-k;i++)
            tmp=tmp->next;//the one before k(th)
        
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
//链表的题目还有很大问题
//依然存在小部分问题
// k=0那边没有考虑啊
//不会了，写的代码错误百出啊
