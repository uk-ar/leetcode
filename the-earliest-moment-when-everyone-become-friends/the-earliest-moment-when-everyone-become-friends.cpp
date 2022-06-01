class Solution {
public:
    vector<int>p;
    int root(int n){
        if(p[n]==-1)
            return n;
        return p[n]=root(p[n]);
    }
    int unite(int a,int b){
        int ra=root(a),rb=root(b);
        if(ra==rb)
            return false;
        if(ra<rb)
            p[rb]=ra;
        else
            p[ra]=rb;
        return true;
    }
    
    int earliestAcq(vector<vector<int>>& l, int n) {
        p.assign(n,-1);
        sort(l.begin(),l.end());
        for(auto &v:l){
            if(unite(v[1],v[2]))
                n--;
            if(n==1)
                return v[0];
        }
        return -1;
    }
};