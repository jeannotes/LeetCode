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
class Solution(object):
	def addTwoNumbers(self, l1, l2):
		dummy = ListNode(0)
		p, flag = dummy, 0

		while 1:
			if(l1 and l2):
				flag += l1.val + l2.val
				l1 = l1.next
				l2 = l2.next
			elif(l1 and (not l2)):
				flag += l1.val
				l1 = l1.next
			elif(l2 and (not l1)):
				flag += l2.val
				l2 = l2.next
			else :
				break
			temp = ListNode(flag % 10)
			flag = flag / 10;
			p.next = temp
			p = p.next
		if flag:
			temp = ListNode(flag % 10)
			p.next = temp
		return dummy.next


if __name__ == '__main__':
    a,a.next,a.next.next = ListNode(2),ListNode(4),ListNode(3)
    b,b.next,b.next.next = ListNode(5),ListNode(6),ListNode(4)
    result = Solution().addTwoNumbers(a,b)
    print "{0}->{1}->{2}".format(result.x,result.next.x,result.next.next.x)

// c language        
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode *l2) {
	struct ListNode *p1 = l1, *p2 = l2;
	int flag = 0;
	struct ListNode *dummy = (struct ListNode *)calloc(1, sizeof(struct ListNode)), *p = dummy;
	while (1) {
		if (p1 && p2) {
			flag += p1->val + p2->val;
			p1 = p1->next;
			p2 = p2->next;
		}
		else if(p1 && !p2) {
			flag += p1->val;
			p1 = p1->next;
		}
		else if (p2 && !p1) {
			flag += p2->val;
			p2 = p2->next;
		}else
			break;
		struct ListNode *temp = (struct ListNode *)calloc(1, sizeof(struct ListNode));
		temp->val = flag % 10;
		p->next = temp;
		p = p->next;
		flag = flag / 10;
		
	}
	if (flag){
		struct ListNode *temp = (struct ListNode *)calloc(1, sizeof(struct ListNode));
		temp->val = flag;
		p->next = temp;
		p = p->next;
	}
	p->next = NULL;
	return dummy->next;
}
// once again this is really helpful
