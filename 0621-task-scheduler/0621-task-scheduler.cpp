class Solution {
public:
    int leastInterval(vector<char>& ta, int n) {
        unordered_map<char,int>m;
        for(auto c:ta)
            m[c]++;
        priority_queue<int>q;
        for(auto [_,cnt]:m)
            q.push(cnt);
        int ti=0;
        while(m.size()>0){
            vector<int>t;
            for(int i=0;i<n+1;i++){
                if(q.size()==0 and t.size()==0)
                    return ti;
                ti++;
                if(q.size()==0)
                    continue;
                auto e=q.top();q.pop();
                if(--e>0)
                    t.push_back(e);
            }
            for(auto e:t)
                q.push(e);
        }
        return ti;
    }
    int leastInterval1(vector<char>& ta, int n) {
        vector<int>f(128);
        for(auto e:ta)
            f[e]++;
        sort(f.begin(),f.end(),greater<int>());
        int f_max=f[0],N=ta.size();
        int idle=(f_max-1)*n;
        for(int i=1;i<128;i++){
            idle-=min(f_max-1,f[i]);
        }
        idle=max(idle,0);
        return N+idle;
    }
};