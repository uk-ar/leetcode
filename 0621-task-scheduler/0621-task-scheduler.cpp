class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        int f_max=0,N=t.size();
        vector<int>v(128);
        if(n==0)
            return N;
        for(int i=0;i<N;i++)
            f_max=max(f_max,++v[t[i]]);//3
        sort(v.begin(),v.end(),greater());//3,3
        int idle=(f_max-1)*n;//2*2->4
        for(int i=1;i<26;i++){
            idle-=min(v[i],f_max-1);
            //cout << i << ":" << v[i] << ":"<<idle <<endl;
        }
        idle=max(idle,0);
        return N+idle;
    }
};