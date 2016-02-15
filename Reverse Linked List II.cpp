class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode *slow=dummy;
        n=n-m;//这一句话不能够放在下面循环的后面，因为m变了。
        while(--m){
            slow=slow->next;//在m个之前的一个
        }
        
        ListNode *fast=slow->next,*tmp;
        while(n--){
            tmp=fast->next;
            fast->next=fast->next->next;
            tmp->next= slow->next;
            slow->next=tmp;
        }
        return dummy->next;
    }
};
//好题目
