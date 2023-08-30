class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>visit(n),in(n);//in degree
        vector<vector<int>>g(n);
        // bfs
        for(auto &v : pre){
            g[v[0]].push_back(v[1]);
            in[v[1]]++;
        }
        // find start
        deque<int>q;
        for(int i = 0; i < n; i++){
            if(in[i]==0){
                q.push_back(i);
            }
        }
        while(q.size()>0){
            int e = q.front();q.pop_front();
            visit[e] = true;
            cout << e <<endl;
            for(auto f : g[e]){
                cout << e <<"->"<<f<<endl;
                in[f]--;
                if(!visit[f] && in[f] == 0)
                    q.push_back(f);
            }
        }
        for(bool e : visit){
            if(!e){
                return false;
            }
        }
        return true;
    }
};