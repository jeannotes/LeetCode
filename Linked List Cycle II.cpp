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
    //https://leetcode.com/problems/linked-list-cycle/
    //  http://www.cnblogs.com/hiddenfox/p/3408931.html
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
		if (head==NULL||head->next==NULL){
			return NULL;
		}

		while (fast!=NULL&&fast->next!=NULL){
			fast=fast->next->next;slow=slow->next;
			if (fast==NULL){
				return NULL;
			}
			if(fast==slow){
			    fast=head;
		        while(fast!=slow){
    		    fast=fast->next;
    		    slow=slow->next;
    		    }
		        return fast;
			}
		}
		return NULL;
    }
    //在while循环里面的if函数没有添加fast->next==NULL，看来前面一个程序也是要重新跑一下。
    //问题出在fast此时是最后一个节点，本身不为NULL，但是fast->next=NULL，所以不会进入循环
    //相反会执行下面的程序。
    //好题目啊，很好的题目
    //函数必须要有输出啊，一直把最后的输出弄成return fast了
};
