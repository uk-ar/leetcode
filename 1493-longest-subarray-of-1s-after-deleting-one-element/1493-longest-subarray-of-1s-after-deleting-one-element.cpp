class Solution {
public:
    int longestSubarray(vector<int>& n) {
        int l=0,r=0,N=n.size(),ans=0,c=0;
        while(l<N){
            if(c<=1)
                ans=max(ans,r-l-c);
            if(r<N and c<=1){
                c+=(n[r]==0);
                r++;
            }else{
                c-=(n[l]==0);
                l++;
            }
        }
        return min(ans,N-1);
    }
};