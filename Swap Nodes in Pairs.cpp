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
//https://leetcode.com/problems/swap-nodes-in-pairs/
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *tail=dummy;
        
        while(head!=NULL&&head->next!=NULL){
            ListNode *tmp=head->next;
            head->next=tmp->next;
            tail->next=tmp;
            tmp->next=head;
            
            tail=head;head=head->next;
            
        }
        head=dummy->next;
        delete dummy;
        
        return head;
    }
};
