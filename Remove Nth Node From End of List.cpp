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
//http://www.programcreek.com/2014/05/leetcode-remove-nth-node-from-end-of-list-java/
//注意快慢指针法
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=head;
        int len=listLen(head);//head的长度
        if(n>len)   return NULL;
        if(n==len) return head->next;
        
        int tem=len-n;
        while(tem>=2){
            dummy=dummy->next;
            tem--;
        }
        if(n==1)    {
            dummy->next=NULL;return head;
        }
        ListNode *tem2=dummy->next->next;
        dummy->next=tem2;
        return head;
    }
    
    //写一个计算链表长度的函数
    int listLen(ListNode *head){
        if(head==NULL){
            return 0;
        }else{
            return 1+listLen( head->next );
        }
    }
};
