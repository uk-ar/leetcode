class Solution {
public:
    bool dfs(int numCourses, vector<vector<int>>& g, vector<int>&visit, int s) {
        if(visit[s]==1)
            return false;
        if(visit[s]==2)
            return true;
        visit[s] = 1;
        for(auto n : g[s]){
            if(!dfs(numCourses,g,visit,n))
                return false;
        }
        visit[s] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort O(N) O(N)
        int N= numCourses;
        vector<int>visit(N);
        // make graph
        vector<vector<int>>g(N);
        for(auto pre : prerequisites){
            g[pre[0]].push_back(pre[1]);
        }
        // dfs
        for(int i = 0; i < N; i++){
            if(visit[i]==0 && !dfs(N,g,visit,i)){
                return false;
            }
        }
        for(int i = 0; i < N; i++){
            if(!visit[i]){
                return false;
            }
        }
        return true;
    }
};