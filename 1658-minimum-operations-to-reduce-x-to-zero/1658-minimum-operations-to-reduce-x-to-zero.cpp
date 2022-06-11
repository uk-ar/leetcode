class Solution {
public:
    int minOperations(vector<int>& n, int x) {
        int N=n.size();
        vector<long>pre(N+1);
        unordered_map<int,long>m;
        m[0]=0;
        for(int i=0;i<N;i++){
            pre[i+1]=pre[i]+n[i];
            m[pre[i+1]]=i+1;
        }
        /*for(auto e:pre)
            cout << e<<" ";
        cout<<endl;
        for(auto p:m)
            cout << p.first << ":" <<p.second <<" ";
        cout<<endl;*/
        long ans=INT_MAX;
        /*if(m.count(x))
            ans=m[x];*/
        long t=0;
        for(int i=N-1;i>=0;i--){
            if(m.count(x-t) and m[x-t]<=i+1)
                ans=min(ans,m[x-t]+N-1-i);
            t+=n[i];            
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};