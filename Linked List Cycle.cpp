class Solution {
public:
    //https://leetcode.com/problems/linked-list-cycle/
    bool hasCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
		if (head==NULL||head->next==NULL){
			return false;
		}

		while (fast!=NULL&&fast->next!=NULL){
			fast=fast->next->next;slow=slow->next;
			if (fast==NULL){
				return false;
			}
			if(fast==slow)
			    return true;
		}
    }
    //一开始程序出错在在一开始的if语句中判断了head->next->next==NULL，
    //如果只有两个链表，可以相互链接嘛，就像一个嘴的形状一样。
    //后来程序出错在没有写成fast=fast->next->next;而写的是fast=fast->next;
    //再后来是while循环里面条件判断没有成功，只设立了一个if (fast==NULL) 加油！！
};
