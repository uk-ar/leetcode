class Solution {
public:
    int N=8;
    int v2b(vector<int>&v){
        int t=0,N=v.size();
        for(int j=0;j<N;j++)
            if(v[j]==1)
                t|=1<<j;
        return t;
    }
    vector<int> b2v(int b){
        vector<int>ans;
        for(int i=0;i<N;i++){
            if((b>>i)&1)
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }
    //bitset
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int N=cells.size();
        unsigned int pre=v2b(cells),cur=0;        
        unordered_map<int,int>m2i;//vector to ind
        vector<int>ans;
        int i;
        for(i=0;i<n;i++){
            if(m2i.count(pre))
                break;
            m2i[pre]=i;
            ans.push_back(pre);            
            pre=~((pre<<1)^(pre>>1));
            pre=pre&0x7e;
        }
        int l=i-m2i[pre];
        if(i==n)
            return b2v(pre);
        int offset=m2i[pre];
        return b2v(ans[(n-offset)%l+offset]);
    }
    vector<int> prisonAfterNDays_vector(vector<int>& cells, int n) {
        int N=cells.size();
        vector<int> pre=cells,cur(N);        
        unordered_map<int,int>m2i;//vector to ind
        vector<vector<int>>ans;
        int i,t;
        for(i=0;i<n;i++){
            t=0;
            for(int j=0;j<N;j++)
                if(pre[j]==1)
                    t|=1<<j;
            //cout << i <<":"<<t<<endl;
            if(m2i.count(t))
                break;
            m2i[t]=i;
            ans.push_back(pre);
            for(int j=1;j+1<N;j++){                
                if(pre[j-1]==pre[j+1])
                    cur[j]=1;
                else
                    cur[j]=0;
            }
            pre=cur;
        }
        int l=i-m2i[t];
        if(i==n)
            return pre;
        int offset=m2i[t];
        return ans[(n-offset)%l+offset];
    }
};