class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,N=h.size(),r=N-1;
        int lm=h[l],rm=h[r],ans=0;
        while(l<r){
            if(lm<rm){
                ans+=min(lm,rm)-h[l];                
                l++;
                lm=max(lm,h[l]);
            }else{
                ans+=min(lm,rm)-h[r];
                r--;
                rm=max(rm,h[r]);
            }
        }
        return ans;
    }
};