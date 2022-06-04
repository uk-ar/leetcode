class Solution {
public:
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wordList) {
        wordList.push_back(bw);
        int N=wordList.size();
        unordered_map<string,int>s2i;
        for(int i=0;i<N;i++)
            s2i[wordList[i]]=i;
        if(s2i.count(ew)==0)
            return {};
        deque<pair<string,vector<int>>>q;
        q.push_back({bw,{N-1}});
        bool f=false;
        vector<vector<int>>ans;
        while(!q.empty() and !f){
            int n=q.size();
            while(n--){
                auto [s,v]=q.front();q.pop_front();
                //cout << s<<endl;
                s2i.erase(s);
                if(s==ew){
                    f=true;
                    ans.push_back(v);
                }
                for(int i=0;i<s.size();i++){
                    for(char c='a';c<='z';c++){
                        string t=s;
                        if(s[i]==c)continue;
                        char o=s[i];
                        s[i]=c;
                        if(s2i.count(s)>0){
                            v.push_back(s2i[s]);
                            //cout << t <<"->" << s<<endl;
                            q.push_back({s,v});
                            v.pop_back();
                        }                        
                        s[i]=o;
                    }
                }
            }
        }
        if(ans.empty())
            return {};
        vector<vector<string>>ans2;
        for(auto &v:ans){
            vector<string>t;
            for(auto e:v)
                t.push_back(wordList[e]);
            ans2.push_back(t);
        }
        return ans2;
    }
};