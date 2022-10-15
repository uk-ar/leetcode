class Solution {
public:
    int numSubarraysWithSum(vector<int>& n, int g) {
        //[1,0,1,0,1]
        //[1,1,2,2,3]
        int N=n.size(),ans=0;
        unordered_map<int,int>m;
        vector<int>pre(N+1);
        m[0]++;
        for(int i=0;i<N;i++){
            pre[i+1]=pre[i]+n[i];
            if(m.count(pre[i+1]-g))
                ans+=m[pre[i+1]-g];
            m[pre[i+1]]++;
        }            
        return ans;
    }
};