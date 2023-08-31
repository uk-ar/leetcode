class LRUCache {
public:
    struct Node{
        int val,key;
        Node *prev,*next;  
        Node(int v,int k){
            key = k;
            val = v;
            //prev = p;
            //next = n;
        }
    };
    Node *head;
    int cap,size=0;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        head->next = head;
        head->prev = head;
    }
    unordered_map<int,Node*>m;
    void del(Node*n){
        n->next->prev = n->prev;
        n->prev->next = n->next;
    }
    void add(Node*n){
        Node*next = head->next;
        head->next = n;
        n->prev = head;
        next->prev = n;
        n->next = next;
    }
    int get(int key) {
        if(!m.count(key)){
            return -1;
        }
        Node* n = m[key];
        del(n);
        add(n);
        return n->val;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            Node* n = m[key];
            n->val = value;
            get(key);
        }else{
            Node *n = new Node(value,key);
            add(n);
            m[key] = n;
            size++;
            if(size>cap){
                size--;
                m.erase(head->prev->key);
                del(head->prev);                
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */