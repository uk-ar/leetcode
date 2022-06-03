class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        int N=s.size();
        vector<int>pre(N,INT_MAX);
        for(int i=0;i<N;i++){
            if(s[i]==1)
                pre[i]=0;
            else if(i>0 and pre[i-1]!=INT_MAX)
                pre[i]=pre[i-1]+1;
        }
        int ans=pre[N-1];
        for(int i=N-1;i-1>=0;i--){            
            pre[i-1]=min(pre[i-1],pre[i]+1);
            ans=max(pre[i-1],ans);
        }
        return ans;
    }
};