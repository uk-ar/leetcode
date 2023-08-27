class Solution {
public:
    unordered_map<string,string>parent;
    string root(string a){
        if(!parent.count(a))
            return a;
        return parent[a] = root(parent[a]);
    }
    bool unite(string a, string b){
        string ra = root(a), rb = root(b);
        if(ra == rb)
            return false;
        if(ra < rb)
            parent[rb] = ra;
        else
            parent[ra] = rb;
        return true;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // union find O(n) O(n)
        unordered_map<string,int>indexes;
        for(int i = 0; i < accounts.size(); i++){
            auto &account = accounts[i];
            for(int j = 1; j+1 < account.size(); j++){
                unite(account[j],account[j+1]);
                indexes[account[j]] = i;
            }            
            indexes[account.back()] = i;
        }
        unordered_map<string,vector<string>>groups;
        for(auto &[email,_] : indexes){
            groups[root(email)].push_back(email);
        }
        vector<vector<string>>ans;
        for(auto &[email,v] : groups){
            vector<string>t = {accounts[indexes[email]][0]};
            sort(v.begin(),v.end());
            t.insert(t.end(),v.begin(),v.end());
            ans.push_back(t);
        }
        return ans;
    }
};