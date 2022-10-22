class Solution {
public:
    int dfs(int i,vector<vector<int>>&g,vector<bool>&vis){
        int ans=1;
        vis[i]=true;
        for(auto &e:g[i]){
            if(vis[e])
                continue;
            ans+=dfs(e,g,vis);
        }
        return ans;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& re) {
        vector<vector<int>>g(n);
        unordered_set<int>r(re.begin(),re.end());
        for(auto &ed:edges){
            if(r.count(ed[0]) or r.count(ed[1]))
                continue;
            g[ed[0]].push_back(ed[1]);
            g[ed[1]].push_back(ed[0]);
        }
        vector<bool>vis(n);
        return dfs(0,g,vis);
    }
};