class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int N=cells.size();
        vector<int> pre=cells,cur(N);        
        unordered_map<int,int>m2i;//vector to ind
        vector<vector<int>>ans;
        vector<int>ans2;
        int i,t;
        for(i=0;i<n;i++){
            t=0;
            for(int j=0;j<N;j++)
                if(pre[j]==1)
                    t|=1<<j;
            cout << i <<":"<<t<<endl;
            if(m2i.count(t))
                break;
            m2i[t]=i;
            ans.push_back(pre);
            ans2.push_back(t);
            for(int j=1;j+1<N;j++){                
                if(pre[j-1]==pre[j+1])
                    cur[j]=1;
                else
                    cur[j]=0;
            }
            pre=cur;
        }
        int l=i-m2i[t];        
        /*cout <<"l:"<< l <<":"<< n%l <<":"<< m2i[t]<<endl;
        for(int i=0;i<ans2.size();i++)
            cout << i<<":"<<ans2[i]<<" ";
        cout<<endl;*/
        if(i==n)
            return pre;
        int offset=m2i[t];
        return ans[(n-offset)%l+offset];
    }
};