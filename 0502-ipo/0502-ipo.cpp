class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        int N=p.size();
        vector<pair<int,int>>v(N);//cost,prof
        for(int i=0;i<N;i++)
            v[i]={c[i],p[i]};//sort by cost
        sort(v.begin(),v.end());
        priority_queue<int>q;//prof
        int j=0;
        for(int i=0;i<k;i++){//k times
            while(j<N and v[j].first<=w){
                q.push(v[j].second);
                j++;
            }
            if(!q.empty()){
                w+=q.top();q.pop();
            }
        }
        return w;
    }
};