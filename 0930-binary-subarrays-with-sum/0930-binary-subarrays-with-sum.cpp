class Solution {
public:
    int numSubarraysWithSum(vector<int>& n, int g) {
        int N=n.size(),i=0,j=0,k=0,ans=0,si=0,sj=0;
        for(k=0;k<N;k++){
            //cout << i << ":" << j <<":"<<k<<endl;
            si+=n[k];
            sj+=n[k];
            while(i<N and si>g)
                si-=n[i++];
            while(j<k and (sj>g or (sj==g and n[j]==0)))
                sj-=n[j++];
            if(si==g)
                ans+=j-i+1;
        }
        return ans;
    }
    int numSubarraysWithSum_(vector<int>& n, int g) {
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