class Solution {
public:
// https://blog.lichangao.com/daily_practice/leetcode/list/array.html#_0147-%E5%AF%B9%E9%93%BE%E8%A1%A8%E8%BF%9B%E8%A1%8C%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F
    ListNode* insertionSortList(ListNode* head) {
        // 0 4  2  6 7 (8)
        //     cur
        ListNode *dummy = new ListNode(0), *cur = head;
        while(cur){
            ListNode *prev = dummy;
            while(prev->next && prev->next->val <= cur->val ){
                prev = prev->next;
            }
            ListNode * tmp = cur->next;
            cur->next = prev->next;
            prev->next = cur;

            cur = tmp;
        }
        return dummy->next;
    }
};
