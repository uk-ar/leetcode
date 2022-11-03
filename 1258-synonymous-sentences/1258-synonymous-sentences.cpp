class Solution {
public:
    map<string,string>p;
    string root(const string &a){
        if(!p.count(a) or p[a]==a)
            return p[a]=a;
        return p[a]=root(p[a]);
    }
    bool unite(string &a,string &b){
        string ra=root(a),rb=root(b);
        if(ra==rb)
            return false;
        if(ra<rb)
            p[rb]=ra;
        else
            p[ra]=rb;
        return true;
    }
    void backtrack(vector<string>&path,vector<string>&ans,int i){
        /*cout << i << endl;
        for(auto e:path)
            cout<<e<<" ";
        cout<<endl;*/
        if(i>=path.size()){
            string t;
            for(auto e:path)
                t+=e+" ";
            t.pop_back();
            ans.push_back(t);
            return;
        }
        string rp=root(path[i]);
        for(auto &[key,parent]:p){
            if(rp==root(key)){
                string ori=path[i];
                path[i]=key;
                backtrack(path,ans,i+1);
                path[i]=ori;
            }
        }
    }
    vector<string> generateSentences(vector<vector<string>>& sy, string te) {
        for(auto &v:sy){
            //cout << v[0]<<":"<<v[1]<<endl;
            unite(v[0],v[1]);
        }
        /*for(auto [i,j]:p)
            cout << i<<":"<<j<<" ";
        cout<<endl;*/
        //cout <<1<<endl;
        vector<string>ans,path;
        stringstream ss(te);
        string word;
        while(ss >> word){
            path.push_back(word);
        }
        backtrack(path,ans,0);
        return ans;
    }
};