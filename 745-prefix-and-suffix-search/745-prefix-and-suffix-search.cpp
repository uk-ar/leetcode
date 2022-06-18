class WordFilter {
public:
    struct Node{
        vector<Node*>ch;
        unordered_set<int>s;
        vector<int>v;
        Node(){
            ch.assign(128,nullptr);
        }
    };
    Node*pre,*suf;
    unordered_map<string,unordered_set<int>>prei;
    unordered_map<string,vector<int>>sufi;
    void insert(Node*root,string &s,int ind,bool pre){  
        string t;
        for(char c:s){
            t+=c;
            if(!root->ch[c])
                root->ch[c]=new Node();
            root=root->ch[c];
            //root->s.emplace(ind);            
            //root->v.push_back(ind);
            if(pre)
                prei[t].emplace(ind);
            else
                sufi[t].push_back(ind);
        }
    }    
    vector<string>ws;
    WordFilter(vector<string>& words) {
        //N*l
        ws=words;
        pre=new Node();
        suf=new Node();
        int N=words.size();
        for(int i=0;i<N;i++){
            insert(pre,words[i],i,true);
            reverse(words[i].begin(),words[i].end());
            insert(suf,words[i],i,false);
        }
        
    }
    unordered_map<string,unordered_map<string,int>>memo;
    int f(string prefix, string suffix) {        
        Node*root=pre;
        reverse(suffix.begin(),suffix.end());
        if(memo[prefix].count(suffix))
            return memo[prefix][suffix];
        //cout << prefix <<":"<<suffix<<endl;
        /*for(char c:prefix){
            if(!root->ch[c])
                return -1;
            root=root->ch[c];
        }
        unordered_set<int> &s=root->s;
        /*cout << "pre:";
        for(auto i:s)
            cout << i <<":"<<ws[i]<<" ";
        cout<<endl;*/
        /*root=suf;
        for(char c:suffix){
            if(!root->ch[c])
                return -1;
            root=root->ch[c];
        }
        vector<int>&v=root->v;
        /*cout << "suf:";
        for(auto i:v)
            cout << i <<":"<<ws[i]<<" ";
        cout<<endl;*/
        
        vector<int>&v=sufi[suffix];
        unordered_set<int> &s=prei[prefix];
        for(auto it=v.rbegin();it!=v.rend();it++){
            if(s.count(*it)){
                return memo[prefix][suffix]=*it;
                //cout << "ans:"<<*it<<":"<<ws[*it]<<endl;
                //return *it;
            }
        }
        return memo[prefix][suffix]=-1;
        //return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */