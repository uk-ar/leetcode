class Solution {
public:
    unordered_map<int,int>parent;
    int root(int a){
        if(!parent.count(a))
            return a;
        return parent[a] = root(parent[a]);
    }
    bool unite(int a, int b){
        int ra = root(a), rb = root(b);
        if(ra == rb){
            return false;
        }
        if(ra < rb){
            parent[rb] = ra;
        }else{
            parent[ra] = rb;
        }
        return true;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        unordered_map<string,int>idx;
        int N = acc.size();
        for(int i = 0; i < N; i++){
            for(int j = 1; j < acc[i].size(); j++ ){
                string email = acc[i][j];
                if(idx.count(email) == 0){
                    idx[email] = i;
                }else{
                    unite(idx[email],i);
                }
            }
        }
        unordered_map<int,vector<string>>group;
        for(auto &[email,i] : idx){
            group[root(i)].push_back(email);
        }
        vector<vector<string>>ans;
        for(auto &[i,v] : group){
            vector<string>t = {acc[i][0]};
            sort(v.begin(), v.end());
            t.insert(t.end(),v.begin(),v.end());
            ans.push_back(t);
        }
        return ans;
    }
};