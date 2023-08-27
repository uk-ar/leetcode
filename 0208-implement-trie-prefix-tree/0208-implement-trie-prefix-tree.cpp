class Trie {
public:
    struct Node{
        vector<Node*>ch;//children
        bool stop;
        Node(){
            stop = false;
            ch.assign(128,nullptr);
        }
    };
    Node *root = nullptr;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *cur = root;
        for(char c : word){
            if(!cur->ch[c]){
                cur->ch[c] = new Node();
            }
            cur = cur->ch[c];
        }
        cur->stop = true;
    }
    
    bool search(string word) {
        Node *cur = root;
        for(char c : word){
            if(!cur->ch[c]){
                return false;
            }
            cur = cur->ch[c];
        }
        return cur->stop;
    }
    
    bool startsWith(string prefix) {
        Node *cur = root;
        for(char c : prefix){
            if(!cur->ch[c]){
                return false;
            }
            cur = cur->ch[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */