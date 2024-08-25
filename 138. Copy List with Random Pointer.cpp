
// https://leetcode.cn/problems/copy-list-with-random-pointer/solutions/2361362/138-fu-zhi-dai-sui-ji-zhi-zhen-de-lian-b-6jeo/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
        unordered_map<Node*, Node*> map;

        Node *cur = head;
        while(cur){
            map[cur] = new Node(cur->val);
            cur=cur->next;
        }

        cur = head;
        while(cur){
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur=cur->next;
        }// 0 1 2 null

        return map[head];
    }
};
Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *head2 = new Node(0), *dummy = head2;
        unordered_map<Node*, Node*>map;
        for(Node *tt = head; tt!=NULL; tt=tt->next, dummy=dummy->next){
            dummy->next = new Node(tt->val);
            map[tt]=dummy->next; 
        }
        dummy=head2;
        for(Node *tt = head; tt!=NULL; tt=tt->next, dummy=dummy->next){
            if(tt->random){
                Node * tmp = map[tt->random];
                dummy->next->random = tmp;
                
            } else{
                dummy->next->random = NULL;
            }
        }
        return head2->next;
    }
