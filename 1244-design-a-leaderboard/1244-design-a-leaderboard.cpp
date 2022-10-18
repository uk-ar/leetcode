class Leaderboard {
public:
    unordered_map<int,int>scores;
    map<int,int,greater<int>>n_players;//num of players for score
    Leaderboard() {
        
    }
    
    void addScore(int id, int score) {
        n_players[scores[id]]--;
        scores[id]+=score;
        n_players[scores[id]]++;
    }
    
    int top(int K) {
        int ans=0;
        for(auto &[v,n]:n_players){
            int a=min(n,K);
            ans+=a*v;
            K-=a;
            if(K==0)
                break;
        }
        return ans;
    }
    
    void reset(int id) {
        addScore(id,-scores[id]);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */