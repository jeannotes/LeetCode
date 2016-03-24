//https://leetcode.com/problems/merge-k-sorted-lists/
//最小堆 最大堆
class Solution {
private:
    class Comp{
        public:
        bool operator()(const ListNode *l1,ListNode *l2){
            return l1->val>l2->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())   
            return NULL;
        
        ListNode *dummy=new ListNode(0),*tail=dummy;
        priority_queue<ListNode *,vector<ListNode *>,Comp>pq;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i])    
                pq.push(lists[i]);
        }
        
        while(!pq.empty()){
            ListNode *tmp=pq.top();pq.pop();
            if(tmp->next)   
                pq.push(tmp->next);
            tail->next=tmp;
            tail=tail->next;
        }
        //pq优先队列里面已经是最大堆，每一个链表的第一个数都是按照最大的顺序排列。
        //有关最大堆最小堆还需要努力加油，不过本题是解决优先队列的一个方法
        //上面那个是按照往大的顺序排列的，最后面的越大
        ListNode *head=dummy->next;
        delete dummy;
        return head;
    }
};
// 要抽时间学习STL基本知识  
//不会啊
// operator 里面不需要使用 &
