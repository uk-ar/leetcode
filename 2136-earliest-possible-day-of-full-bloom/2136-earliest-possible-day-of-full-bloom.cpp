class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        int N=pt.size();
        vector<vector<int>> v(10000+1);
        for(int i=0;i<N;i++)
            v[gt[i]].push_back(i);
        int d=0,ans=0;
        for(int i=10000;i>=0;i--)
            for(auto j:v[i]){
                ans=max(ans,d+pt[j]+gt[j]);
                d+=pt[j];
            }
        return ans;
    }
};