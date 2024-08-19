class Solution {// https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#%E6%80%9D%E8%B7%AF
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        
        ListNode *fast = head, *slow=head;
    //  http://www.cnblogs.com/hiddenfox/p/3408931.html        
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow){
                slow = head;
                
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
    //相反会执行下面的程序。 今天 今天下午笔试 
    //好题目啊，很好的题目
    //函数必须要有输出啊，一直把最后的输出弄成return fast了	
};
