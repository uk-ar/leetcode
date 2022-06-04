class Solution {
public:
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
        //wl.push_back(bw);
        deque<vector<string>>q;
        q.push_back({bw});
        int N=wl.size();
        unordered_set<string>ws(wl.begin(),wl.end());
        bool f=false;
        vector<vector<string>>ans;
        while(!q.empty() and !f){
            int n=q.size();
            while(n--){
                vector<string> v=q.front();q.pop_front();
                string s=v.back();
                ws.erase(s);
                if(s==ew){
                    f=true;
                    ans.push_back(v);
                }
                for(int i=0;i<s.size();i++){
                    for(char c='a';c<='z';c++){
                        if(s[i]==c)continue;
                        char o=s[i];
                        s[i]=c;
                        if(ws.count(s)>0){
                            v.push_back(s);
                            q.push_back(v);
                            v.pop_back();
                        }
                        s[i]=o;
                    }
                }
            }
        }
        return ans;
    }
};