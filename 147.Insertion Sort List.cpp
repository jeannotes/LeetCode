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

https://www.programiz.com/cpp-programming/online-compiler/
// Online C++ compiler to run C++ program online
#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL ) return head;
        ListNode *dummy = new ListNode(0), *cur = head;
        // dummy->next=head;
        while(cur){
            std::cout << "out:: " << cur->val<< std::endl;
            ListNode *prev = dummy, *next = cur->next;
            while(prev->next && prev->next->val<=cur->val){
                std::cout << "in:: " << prev->next->val<< std::endl;
                // 0,4,2,5
                prev = prev->next;
            }
            cur->next = prev->next;
            prev->next=cur;
            std::cout << "last:: " << prev->next->val<< std::endl;
            cur = next;
        }
        return dummy->next;
    }
};


int main() {
    // Write C++ code here
    // std::cout << "Try programiz.pro";
    Solution s= Solution();
    // [4,2,1,3]
    ListNode *a = new ListNode(4);
    ListNode *b = new ListNode(2);
    a->next = b;
    ListNode *c =s.insertionSortList(a);
    std::cout << "res: "<<c->val;
    return 0;
}
