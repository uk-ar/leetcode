class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](auto &l,auto &r){
            return l[1]<r[1];
        });
        long pre=LONG_MIN,N=p.size(),ans=0;
        for(int i=0;i<N;i++){
            if(pre<p[i][0]){
                ans++;
                pre=p[i][1];
            }
        }
        return ans;
    }
};