class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while(slow && fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                
                return true;
            }
        }

        return false;
    }
};
    //一开始程序出错在在一开始的if语句中判断了head->next->next==NULL，心情不好
    //如果只有两个链表，可以相互链接嘛，就像一个嘴的形状一样。还是不会啊， 今天 今天下午 今天下午笔试 
    //后来程序出错在没有写成fast=fast->next->next;而写的是fast=fast->next;
    //再后来是while循环里面条件判断没有成功，只设立了一个if (fast==NULL) 加油！！，可以啊
 
