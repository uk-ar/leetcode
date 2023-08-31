class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // bfs from leaf O(N)
        // build tree
        vector<vector<int>>t(n);
        vector<int> indeg(n);
        for(auto &e : edges){
            t[e[0]].push_back(e[1]);
            t[e[1]].push_back(e[0]);
            indeg[e[0]]++;
            indeg[e[1]]++;
        }
        // find leafs
        deque<int>q;
        for(int i = 0; i < n; i++){
            if(indeg[i]==1){
                q.push_back(i);
            }
        }
        if(n==1)
            return {0};
        // remove leafs
        vector<int> last;
        //vector<bool> visited(n);
        while(q.size()>0){            
            last.clear();
            int n = q.size();
            while(n--){
                int e = q.front();q.pop_front();
                //visited[e] = false;
                for(int f : t[e]){
                    indeg[f]--;
                    //if(!visited[f] && indeg[f]==1){
                    if(indeg[f]==1){
                        q.push_back(f);
                    }
                }
                last.push_back(e);
            }
        }       
        // return remain elements in last iteration
        return last;
    }
};