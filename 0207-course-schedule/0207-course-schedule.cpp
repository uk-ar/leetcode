class Solution {
public:
    void dfs(vector<vector<int>>& g,vector<bool>&visit,int i,vector<int>&in) {
        if(visit[i])
            return;
        visit[i]=true;
        for(auto e : g[i]){
            in[e]--;
            if(in[e]==0 && !visit[e])
                dfs(g,visit,e,in);
        }
    }
    bool canFinish(int N, vector<vector<int>>& pre) {
        vector<int>in(N);
        vector<vector<int>>g(N);
        for(auto &v:pre){
            in[v[1]]++;
            g[v[0]].push_back(v[1]);
        }
        vector<bool>visit(N);
        for(int i = 0; i < N; i++){
            if(in[i]==0){
                 dfs(g,visit,i,in);
            }
        }
        for(int i = 0; i < N; i++){
            if(!visit[i])
                return false;
        }
        return true;
    }
};