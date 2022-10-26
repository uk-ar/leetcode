class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        long r=0,l=0,N=p.size(),ans=0;
        for(r=0;r<N;r++){
            while(p[l]-p[r]!=r-l){
                l++;
            }
            //cout << l << ":" << r <<":"<<ans<<endl;
            ans+=r-l+1;
        }
        return ans;
    }
};