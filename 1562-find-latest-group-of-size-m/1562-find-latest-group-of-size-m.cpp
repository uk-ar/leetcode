class Solution {
public:
    vector<int>p;
    vector<int>s;
    int root(int i){
        if(p[i]==-1)
            return i;
        return p[i]=root(p[i]);
    }
    int unite(int a,int b){
        int ra=root(a),rb=root(b);
        if(ra==rb)
            return s[ra];
        if(ra<rb){            
            p[rb]=ra;
            s[ra]+=s[rb];
            return s[ra];
        }else{            
            p[ra]=rb;
            s[rb]+=s[ra];
            return s[rb];
        }
    }
    int findLatestStep(vector<int>& a, int m) {
        int N=a.size(),ans=-1;
        p.assign(N,-1);
        s.assign(N,0);
        vector<int>v(N,0);
        int i=1;
        unordered_map<int,int>f;
        for(auto e:a){
            e--;
            v[e]=1;
            s[e]=1;
            f[1]++;
            if(e-1>=0 and v[e-1]==1){
                f[s[root(e-1)]]--;
                f[s[root(e)]]--;
                f[unite(e-1,e)]++;                
            }
            if(e+1<N and v[e+1]==1){
                f[s[root(e+1)]]--;
                f[s[root(e)]]--;
                f[unite(e,e+1)]++;
            }
            if(f[m]>0)
                ans=i;               
            i++;
            /*for(auto e:p)
                cout << e << " ";
            cout<<":p"<<endl;
            for(auto e:s)
                cout << e << " ";
            cout<<":s"<<endl;
            cout << i << ":" <<e<<":"<< ans<<endl;*/
        }
        return ans;
    }
};