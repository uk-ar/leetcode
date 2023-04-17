class Solution {
public:
    int leastInterval(vector<char>& ta, int n) {
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