class Solution {
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int N=s.size();
        vector<vector<int>>vv(N);
        for(int i=0;i<N;i++)
            vv[i]={s[i],e[i],p[i]};
        sort(vv.begin(),vv.end());
        using pii=pair<int,int>;//index,prof
        priority_queue<pii,vector<pii>,greater<pii>>q;
        int c=0;
        for(int i=0;i<N;i++){
            while(q.size()>0 and q.top().first<=vv[i][0]){
                c=max(c,q.top().second);
                q.pop();
            }
            q.push({vv[i][1],c+vv[i][2]});
        }
        while(q.size()>0){
            c=max(c,q.top().second);
            q.pop();
        }
        return c;
    }
};