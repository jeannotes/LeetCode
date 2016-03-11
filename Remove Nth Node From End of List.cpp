//注意快慢指针法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=getLength(head);
        ListNode* dummy=head;
        if(n>len)   return NULL;
        if(n==len)  return head->next;
        
        // 1-2-3-(4)-5
        int tem=len-n;
        while(--tem){
            dummy=dummy->next;
        }
        dummy->next=dummy->next->next;
        return head;
    }
    
    int getLength(ListNode* head){
        if(head!=NULL){
            return 1+getLength(head->next);
        }else
            return 0;
    }
};
//一次通过，注意特殊案例
