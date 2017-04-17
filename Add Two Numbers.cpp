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
//1 继续练习

//python
class ListNode(object):
    def __init__(self,x):
        self.x=x
        self.next=None

class Solution(object):
    def addTwoNumbers(self,l1,l2):
        dummy=ListNode(0);
        current,carry = dummy,0

        while l1 or l2 :
            val = carry
            if l1 :
                val+=l1.x
                l1=l1.next
            if l2 :
                val +=l2.x
                l2=l2.next
            carry,val = val/10 , val%10
            current.next= ListNode(val)
            current=current.next

        if carry :
            current.next = ListNode(carry)
        return  dummy.next

if __name__ == '__main__':
    a,a.next,a.next.next = ListNode(2),ListNode(4),ListNode(3)
    b,b.next,b.next.next = ListNode(5),ListNode(6),ListNode(4)
    result = Solution().addTwoNumbers(a,b)
    print "{0}->{1}->{2}".format(result.x,result.next.x,result.next.next.x)
