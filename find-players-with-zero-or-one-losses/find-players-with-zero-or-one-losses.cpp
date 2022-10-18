class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>w,l;
        for(auto &v:matches){
            w[v[0]]++;
            l[v[1]]++;
        }
        vector<vector<int>>ans(2);
        for(auto &[k,v]:w){
            if(l.count(k)==0)
                ans[0].push_back(k);
        }
        for(auto &[k,v]:l){
            if(v==1){
                ans[1].push_back(k);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};