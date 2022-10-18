class RecentCounter {
public:
    deque<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!q.empty() and q.front()<t-3000){
            q.pop_front();
        }
        q.push_back(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */