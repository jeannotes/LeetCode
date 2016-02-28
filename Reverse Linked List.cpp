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
//还有一种递归的写法。
//https://github.com/JSRGFJZ/leetcode-5/blob/master/algorithms/reverseLinkedList/reverseLinkedList.cpp#L38
    ListNode* reverseList(ListNode* head) {
        ListNode *tail=NULL;
        
        if(head==NULL)  return head;
        
        while(head!=NULL){
            ListNode *tmp=head->next;
            head->next=tail;
            tail=head;
            head=tmp;
        }
        head=tail;
        return head;
    }
};
//ListNode *tail=NULL;  空链表
//一次通过
