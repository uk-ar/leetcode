class Solution {
public:
    vector<int>p;
    int root(int a){
        if(p[a]==-1)
            return a;
        return p[a]=root(p[a]);
    }
    bool unite(int a,int b){
        int ra=root(a),rb=root(b);
        if(ra==rb)
            return false;
        if(ra<rb){
            p[rb]=ra;
        }else{
            p[ra]=rb;
        }
        return true;
    }
    int minCostToSupplyWater(int n, vector<int>& we, vector<vector<int>>& pi) {
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({we[i],0,i+1});
        }
        for(auto &p:pi)
            v.push_back({p[2],p[0],p[1]});
        sort(v.begin(),v.end());        
        p.assign(n+1,-1);
        int ans=0;
        for(auto e:v){
            int r0=root(e[1]),r1=root(e[2]);
            if(r0==r1)continue;
            ans+=e[0];
            unite(r0,r1);
        }
        return ans;
    }
};