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
//https://leetcode.com/problems/rotate-list/
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0)
            return head;
        ListNode *last=head;//寻找最后节点
        
        int count=1;
        while(last->next!=NULL){
            last=last->next;
            count++;
        }
        
        k=k%count;
        if(k==0)
            return head;
            
        ListNode *tmp=head;
        
        for(int i=1;i<count-k;i++){
            //k是从后往前看的
            tmp=tmp->next;
        }
        //此时tmp指着例题里面的3
        last->next=head;
        head=tmp->next;
        tmp->next=NULL;
        return head;
    }
};
