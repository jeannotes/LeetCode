/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//https://leetcode.com/problems/insertion-sort-list/
class Solution
{
public:
	ListNode *insertionSortList(ListNode *head){
		if(head==NULL||head->next==NULL)
			return head;

		ListNode *dummy=new ListNode(0);
		dummy->next=head;

		while (head->next!=NULL){
			ListNode *p=dummy;
			while (p!=head&&p->next->val<=head->next->val){
				p=p->next;
			}

			if (p==head){
				//说明这一段数字都是小于此时刻的head->next->val
				head=head->next;
				continue;
			}

			ListNode *temp=head->next->next;
			head->next->next=p->next;
			p->next=head->next;
			head->next=temp;
			//这一块比较重要，尤其是链表的转移，切记先保存链表的下一个节点
		}
		//最后结束时候让head重回起点。
		head=dummy->next;
		delete dummy;
		return head;
	}
};
