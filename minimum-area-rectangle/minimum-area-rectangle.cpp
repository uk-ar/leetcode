class Solution {
public:
    int minAreaRect(vector<vector<int>>& ps) {
        unordered_map<int,unordered_set<int>>mp;
        for(auto p:ps)
            mp[p[0]].emplace(p[1]);
        int N=ps.size(),ans=INT_MAX;
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++){
                int x0=ps[i][0],y0=ps[i][1];
                int x1=ps[j][0],y1=ps[j][1];
                if(x0==x1 or y0==y1)
                    continue;
                if(mp[x0].count(y1)==0 or mp[x1].count(y0)==0)
                    continue;                
                ans=min(ans,abs(x0-x1)*abs(y0-y1));
                //cout << x0 <<":"<<y0<<" "<<x1<<":"<<y1<<" "<<ans<<endl;
            }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};