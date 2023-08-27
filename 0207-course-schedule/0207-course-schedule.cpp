class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& pre) {
        vector<vector<int>>g(N);
        vector<int>in(N);
        for(auto v : pre){
            in[v[1]]++;
            g[v[0]].push_back(v[1]);            
        }
        // bfs
        deque<int>q;
        for(int i = 0; i < N; i++){
            if(in[i] == 0){
                q.push_back(i);
            }
        }
        vector<bool>visit(N);
        while(q.size() > 0){
            int e = q.front();q.pop_front();
            visit[e] = true;
            for(auto n : g[e]){
                in[n]--;
                if(in[n] == 0){
                    q.push_back(n);
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(!visit[i])
                return false;
        }
        return true;
    }
};