class Leaderboard {
public:
    unordered_map<int,int>m;
    Leaderboard() {
        
    }
    
    void addScore(int id, int s) {
        m[id]+=s;
    }
    
    int top(int K) {
        K--;
        vector<pair<int,int>>v(m.begin(),m.end());
        nth_element(v.begin(),v.begin()+K,v.end(),[](auto l,auto r){
            return l.second > r.second;
        });
        int ans=0;
        for(int i=0;i<=K;i++)
            ans+=v[i].second;
        return ans;
    }
    
    void reset(int id) {
        m[id]=0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */