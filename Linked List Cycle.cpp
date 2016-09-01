class Solution {
public:
    //https://leetcode.com/problems/linked-list-cycle/
    //待会说明下，刚刚那题还有一种n平方解法
    //http://blog.sina.com.cn/s/blog_6f611c300101fs1l.html
bool hasCycle(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return false;
	ListNode* fast = head, *slow = head;
	while (fast&&fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == NULL)
			return false;
		if (fast == slow)
			return true;
	}
	return false;
}
    //一开始程序出错在在一开始的if语句中判断了head->next->next==NULL，
    //如果只有两个链表，可以相互链接嘛，就像一个嘴的形状一样。还是不会啊
    //后来程序出错在没有写成fast=fast->next->next;而写的是fast=fast->next;
    //再后来是while循环里面条件判断没有成功，只设立了一个if (fast==NULL) 加油！！，可以啊
};
