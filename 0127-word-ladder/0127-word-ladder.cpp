class Solution {
public:
    int ladderLength(string b, string e, vector<string>& ws) {
        unordered_set<string>se(ws.begin(),ws.end());
        deque<string>q({b});
        int ans=1,N=b.size();
        while(q.size()>0){
            auto n=q.size();
            while(n--){
                auto f=q.front();q.pop_front();
                if(f==e)
                    return ans;
                for(int i=0;i<N;i++){
                    char o=f[i];
                    for(char c='a';c<='z';c++){
                        f[i]=c;
                        if(se.count(f)){
                            q.push_back(f);
                            se.erase(f);
                        }
                    }
                    f[i]=o;
                }
            }
            ans++;
        }
        return 0;
    }
};