class LRUCache{
private:
    struct Node{
        int key;
        int value;
        Node *prev,*next;
        Node(int k,int v):key(k),value(v),prev(NULL),next(NULL){}
    };
    
    unordered_map<int , Node*>mapper;
    Node *head,*tail;
    int capacity;
    
    void insert(Node *target){
        target->next=head->next;
        head->next->prev=target;
        head->next=target;
        target->prev=head;
    }
    
    void split(Node *target){
        target->prev->next=target->next;
        target->next->prev=target->prev;
        //insert(target);
    }
    
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;//设立开头结尾指针，方便操作
        tail->prev=head;
    }
    
    int get(int key) {
        if(mapper.find(key)==mapper.end()){
            return -1;
        }
        Node *target=mapper[key];
        
        if(target!=head->next){//如果不是第一个，那么根据最小使用原则，使用了一次target，把他挪到
                             //最前面
            split(target);
            insert(target);
        }
        
        return target->value;
    }

    void set(int key, int value) {
        if(get(key)!=-1){//  数值已经存在
            head->next->value=value;//get 这个函数里面已经有分离 插入 这些操作了.
            return;
            
        }
        //下面判断不存在，但是要考虑是否越界
        
        Node *tmp=NULL;
        if(mapper.size()==capacity){
            tmp=tail->prev;
            split(tmp);
            mapper.erase(tmp->key);
            tmp->value=value;
            tmp->key=key;
        }/*
            tmp->value=value;
            tmp->key=key;*/  // 不能这么写，因为上面定义的tmp是一个单链表指针，这样赋值是双链表指针
        tmp=new Node(key,value);
        mapper[key]=tmp;
        insert(tmp);
    }
};
