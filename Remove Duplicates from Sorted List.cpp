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
    ListNode* deleteDuplicates(ListNode* head) {
    //https://leetcode.com/problems/remove-duplicates-from-sorted-list/
        if(head==NULL||head->next==NULL)
            return head;
        
        ListNode *t=head;
        while(head->next!=NULL){
            if(head->val==head->next->val){
                ListNode *tmp = head->next->next;
                delete head->next;
                head->next = tmp;
            }else
                head=head->next;
        }
        return t;
    }
};
