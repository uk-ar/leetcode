class AutocompleteSystem {
public:
    vector<string> i2s;
    vector<int> i2t;
    string t;
    class Node{
        public:
        vector<Node*>ch;
        string s="";
        vector<Node*>hot;
        int times=0;
        Node():ch(128,nullptr){}
        void update(Node*n){
            if(find(hot.begin(),hot.end(),n)==hot.end())
                hot.push_back(n);
            sort(hot.begin(),hot.end(),[](auto l,auto r){
                if(l->times==r->times)
                    return l->s<r->s;
                return l->times>r->times;
            });
            if(hot.size()>3)
                hot.pop_back();
        }
    };
    
    struct Node*root,*cur;
    void insert(string s,int times){        
        Node* cur=root;
        vector<Node*>v;
        for(char c:s){
            if(!cur->ch[c])
                cur->ch[c]=new Node();            
            cur=cur->ch[c];
            v.push_back(cur);
        }
        cur->s=s;
        cur->times+=times;
        for(auto e:v)
            e->update(cur);
    }
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) : i2s(sentences),i2t(times){       
        root=new Node();
        int N=sentences.size();
        for(int i=0;i<N;i++){
            insert(sentences[i],times[i]);
        }
        cur=root;
    }
    
    vector<string> input(char c) {
        if(c=='#'){
            insert(t,1);
            t="";
            cur=root;
            return {};
        }
        t+=c;
        if(!cur->ch[c])
            cur->ch[c]=new Node();
        cur=cur->ch[c];
        vector<string>ans;  
        for(int i=0;i<3 and i<cur->hot.size();i++){
            ans.push_back(cur->hot[i]->s);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */