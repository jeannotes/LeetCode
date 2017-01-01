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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp=new ListNode(0),*tail=temp;
        int flag=0;
        while(l1||l2){
            if(l1){
                flag+=l1->val;
                l1=l1->next;
            }
            if(l2){
                flag+=l2->val;
                l2=l2->next;
            }
            tail->next=new ListNode(flag%10);
            flag=flag/10;
            tail=tail->next;
        }
        // 最后可能l1，l2都已经结束 ， 但是最后两位相加有进位。
        if(flag){
            tail->next=new ListNode(flag);
        }
        l1=temp->next;//因为tail一直在后移，最后输出tail就出错，相反
        //temp一直在第一位  还行啊
        delete temp;
        return l1;
    }
};
//1
