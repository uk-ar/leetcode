class LRUCache {
public:
    struct Node{
        Node*prev=nullptr,*next=nullptr;
        int key,value;
        Node(int k,int v){
            key=k;
            value=v;
        }
    };  
    Node *root;
    int cap;
    LRUCache(int capacity) {
        root=new Node(-1,-1);
        root->next=root;
        root->prev=root;
        cap=capacity;
    }
    void add(Node*node){
        Node*next=root->next;
        node->next=next;
        node->prev=root;
        root->next=node;
        next->prev=node;
    }
    void del(Node*node){
        Node*prev=node->prev,*next=node->next;
        prev->next=next;
        next->prev=prev;
    }
    unordered_map<int,Node*>m;
    int get(int key) {
        if(m.count(key)==0)
            return -1;
        del(m[key]);
        add(m[key]);
        return m[key]->value;
    }
    int size=0;
    void put(int key, int value) {
        if(m.count(key)){
            m[key]->value=value;
            del(m[key]);
        }else{
            m[key]=new Node(key,value);
            size++;
        }
        add(m[key]);
        if(size>cap){
            size--;
            m.erase(root->prev->key);
            del(root->prev);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */