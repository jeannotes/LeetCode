/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p=NULL,*t=NULL,*h=NULL;
        
        unordered_map<RandomListNode *,int>m;
        int pos=0;
        for(p=head;p!=NULL;p=p->next,pos++){
            m[p]=pos;
        }
        
        //开始克隆，不进行任何的random变换
        vector<RandomListNode *>v;
        for(p=head;p!=NULL;p=p->next){
            RandomListNode *node=new RandomListNode(p->label);
            v.push_back(node);
            if(h==NULL){
                h=t=node;
            }else{
                t->next=node;
                t=t->next;
            }
        }
        
        //开始操作那些random链表
        t=h;
        for(p=head;p!=NULL&&t!=NULL;p=p->next,t=t->next){
            if(p->random!=NULL){
                t->random=v[m[p->random]];
            }
        }
        
        return h;
    }
};
//好题目
