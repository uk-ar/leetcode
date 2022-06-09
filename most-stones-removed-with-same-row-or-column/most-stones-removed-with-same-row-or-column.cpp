class Solution {
public:
    void dfs(vector<vector<int>>& st,unordered_map<int,vector<int>>&xi,unordered_map<int,vector<int>>&yi,vector<bool>&vis,int i) {
        int x=st[i][0],y=st[i][1];
        vis[i]=true;
        for(auto j:xi[x])
            if(!vis[j])
                dfs(st,xi,yi,vis,j);
        for(auto j:yi[y])
            if(!vis[j])
                dfs(st,xi,yi,vis,j);
    }
    int removeStones(vector<vector<int>>& st) {
        unordered_map<int,vector<int>>xi,yi;//{x:[i]}
        int N=st.size();
        for(int i=0;i<N;i++){
            int x=st[i][0],y=st[i][1];
            xi[x].push_back(i);
            yi[y].push_back(i);
        }
        vector<bool>vis(N);
        int ans=0;
        for(int i=0;i<N;i++){
            if(vis[i]==false){
                dfs(st,xi,yi,vis,i);
                ans++;
            }
        }
        return N-ans;
    }
};