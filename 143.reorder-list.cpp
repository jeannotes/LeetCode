/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        vector<ListNode*> vec;
        ListNode *dummy = head;
        while(dummy){
            vec.push_back(dummy);dummy=dummy->next;
        }
        // 0 1 
        // 0 1 2
        int i=0, j=vec.size()-1;
        while(i<j){
            vec[i]->next = vec[j];
            i++;
            if(i==j) break;
            vec[j]->next=vec[i];
            j--;
        }
        vec[i]->next=NULL;
        return;
    }
};
