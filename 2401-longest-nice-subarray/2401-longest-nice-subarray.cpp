class Solution {
public:
    int longestNiceSubarray(vector<int>& n) {
        int l=0,r=0,N=n.size(),t=0,ans=0;
        while(l<N){                
            if(r<N and (t&n[r])==0){
                t|=n[r];
                r++;
                ans=max(ans,r-l);
            }else{
                t&=~n[l];
                l++;
            }
        }
        return ans;
    }
};