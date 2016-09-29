TreeNode* sortedListToBST(ListNode* head) {
	return sortedHelper(head, 0, getLength(head) - 1);
}

TreeNode* sortedHelper(ListNode* &head,int i,int j) {
	if (i > j || head == NULL)
		return NULL;
	int mid = (i + j) / 2;
	TreeNode* left = sortedHelper(head, i, mid - 1);
	TreeNode* node = new TreeNode(head->val);
	head = head->next;
	TreeNode* right = sortedHelper(head, mid + 1, j);
	node->left = left;
	node->right = right;
	return node;
}

int getLength(ListNode* head) {
	if (head == NULL)
		return 0;
	return 1 + getLength(head->next);
	}
//还是有些不太理解,注意引用啊，不然就会出错，
//这里简单介绍如何解题，假设此时只有 0，两个1,0 必然指向null，head=head->next 就是刚刚的1,0 
//以此解题,记住是引用  head每次都在后移的，每一个循环都在后移
//  不会啊，加油，稍微能够理清楚了，还行，感觉会了一点
//  类似于中序遍历一样，不会了  明天考试了
class Solution {
public:

    TreeNode *sortedListToBST(ListNode *head) {
        return build(head, NULL);
    }

    TreeNode* build(ListNode* start, ListNode* end) {
        if(start == end) {
            return NULL;
        }

        ListNode* fast = start;
        ListNode* slow = start;

        while(fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* node = new TreeNode(slow->val);
        node->left = build(start, slow);
        node->right = build(slow->next, end);

        return node;
    }
};

//好方法啊,第二天做，没事，现在感觉第二种方法很好，晚上还可以的，然而又不会了
