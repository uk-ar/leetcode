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
            //cout << we[i] << " "<<0<<":"<< i <<endl;
        }
        for(auto &p:pi)
            v.push_back({p[2],p[0],p[1]});
        sort(v.begin(),v.end());
        for(auto e:v)
            cout << e[0] <<":"<<e[1]<<":"<<e[2]<<endl;
        cout<<endl;
        p.assign(n+1,-1);
        //w.assign(n+1,false);
        int ans=0;
        for(auto e:v){
            /*if(e.size()==2){
                int r=root(e[1]);
                //cout << e[1] << "("<<r<<endl;
                if(w[r])continue;                
                ans+=e[0];
                w[r]=true;
            }else{*/
                int r0=root(e[1]),r1=root(e[2]);
                if(r0==r1)continue;
                //if(w[r0] and w[r1])continue;                
                ans+=e[0];
                /*if(w[r0])
                    w[r1]=true;
                if(w[r1])
                    w[r0]=true;*/
                unite(r0,r1);
            //}
            for(auto t:e)
                cout << t <<" ";
            cout <<":"<<ans <<endl;
        }
        return ans;
    }
};