class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        int N=pt.size();
        vector<vector<int>>v(N);        
        for(int i=0;i<N;i++)
            v[i]={pt[i],gt[i]};
        sort(v.begin(),v.end(),[](auto &l,auto &r){
            if(l[1]==r[1])
                l[0]>r[0];
            return l[1]>r[1];
        });
        int i=0,ans=0;
        for(auto &p:v){
            //cout <<i<<":"<< p[0]<<":"<<p[1]<<endl;
            ans=max(ans,i+p[0]+p[1]);
            i+=p[0];
        }
        return ans;
    }
};