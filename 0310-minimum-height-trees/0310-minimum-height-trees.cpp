class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& ed) {
        vector<vector<int>>G(n);
        vector<int>IN(n);
        for(auto &v:ed){
            G[v[0]].push_back(v[1]);
            G[v[1]].push_back(v[0]);
            IN[v[0]]++;
            IN[v[1]]++;
        }
        if(n==1)
            return {0};
        deque<int>q;
        for(int i=0;i<n;i++)
            if(IN[i]==1)
                q.push_back(i);
        while(q.size()>0){
            int n=q.size();
            vector<int>ans;
            while(n--){
                int e=q.front();q.pop_front();                
                ans.push_back(e);
                for(auto i:G[e]){
                    if(--IN[i]==1){
                        q.push_back(i);
                    }
                }
            }
            if(q.size()==0)
                return ans;
        }
        return {};
    }
};