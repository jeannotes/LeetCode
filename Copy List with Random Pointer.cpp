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
        t->next=NULL;//这边最好加上这句话，最后指向null
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
// hash表容易出错
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head){
    	if (head==NULL){
    		return head;
    	}
    	RandomListNode *l1,*l2,*newHead;
    	for (l1=head;l1!=NULL;l1=l1->next){
    		RandomListNode *node=new RandomListNode(l1->label);
    		node->next=l1->next;l1->next=node;l1=l1->next;
    	}
    
    	for (l1=head;l1!=NULL;l1=l1->next->next){
    		if (l1->random){
    			l1->next->random=l1->random->next;
    		}
    	}
    	newHead=head->next;
    	for (l1=head;l1!=NULL;l1=l1->next){
    		l2=l1->next;
    		l1->next=l2->next;
    		if(l2->next){
    			//1 2 3 4 5 6
    			l2->next=l2->next->next;
    		}
    	}
    	return newHead;
    }
};
// 真是好题目啊
// 好题目的，真有想法
