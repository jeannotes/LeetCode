
// 好题目，做了好几遍
// 在最后把两个分开还是有问题啊 
RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL )
		return head;
	RandomListNode *l1,*l2,*newHead;
	for (l1 = head; l1 != NULL;l1=l1->next) {
		RandomListNode *tmp = new RandomListNode(l1->label);
		tmp->next = l1->next;
		l1->next = tmp;
		l1 = l1->next;
	}
	// 此时已经复制ok

	for (l1 = head; l1 != NULL; l1 = l1->next) {
		if (l1->random) {
			l1->next->random = l1->random->next;
		}
		l1 = l1->next;
	}
	l1 = head;
	newHead = l1->next;

	for (l1 = head; l1 != NULL; l1 = l1->next) {
		l2 = l1->next;
		l1->next = l1->next->next;//11 22 33
		if (l2->next) {
			l2->next = l2->next->next;
		}
	}
	return newHead;
}
//还是要为自己鼓掌啊，本来一开始都不想做的，还是咬紧牙关，做下去了
// 不能够写head->next==NULL  这样按照所写的程序会出错，因为这样直接返回的引用啊
