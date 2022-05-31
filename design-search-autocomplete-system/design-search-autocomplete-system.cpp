class AutocompleteSystem {
public:
    vector<string> i2s;
    unordered_map<string,int> s2i;
    vector<int> ti;
    string t;
    struct Node{
        vector<Node*>ch;
        bool stop=false;
        vector<int>ind;
        Node():ch(128,nullptr){
        }
    };
    
    struct Node*root,*cur;
    void insert(string s){        
        Node* cur=root;
        int i=s2i[s];
        for(char c:s){
            if(!cur->ch[c])
                cur->ch[c]=new Node();
            cur=cur->ch[c];
            cur->ind.push_back(i);
        }
        cur->stop=true;
    }
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) : i2s(sentences),ti(times){       
        root=new Node();
        int N=sentences.size();
        for(int i=0;i<N;i++){
            string &s=sentences[i];
            s2i[s]=i;
            insert(s);
        }
        cur=root;
    }
    
    vector<string> input(char c) {
        if(c=='#'){
            if(s2i.count(t)==0){
                int i=ti.size();
                ti.push_back(1);
                i2s.push_back(t);
                s2i[t]=i;
                insert(t);
            }else{
                int i=s2i[t];
                ti[i]++;
            }
            t="";
            cur=root;
            return {};
        }
        t+=c;
        if(!cur->ch[c])
            cur->ch[c]=new Node();
        cur=cur->ch[c];
        vector<string>ans;  
        vector<int> &v=cur->ind;
        partial_sort(v.begin(),v.begin()+min(3,(int)v.size()),v.end(),[&](auto l,auto r){
            if(ti[l]==ti[r])
                return i2s[l]<i2s[r];
            return ti[l]>ti[r];
        });
        for(int i=0;i<3 and i<v.size();i++){
            cout << v[i] <<":"<< ti[v[i]] <<":"<< i2s[v[i]]<<endl;
            ans.push_back(i2s[v[i]]);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */