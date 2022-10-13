class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(),l=0,r=0,ans=0,max_count=0;
        vector<int> v(128);
        while(l<n){
            if(r-l-max_count<=k)
                ans=max(ans,r-l);
            if(r<n and r-l-max_count<=k){
                max_count=max(max_count,++v[s[r]]);
                r++;
            }else{
                --v[s[l]];
                l++;
            }
        }
        return ans;
    }
};