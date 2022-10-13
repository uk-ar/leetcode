class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int l=0,r=0,ans=0,n=a.size(),max_count=0;
        vector<int> cnt(128);//true,false
        while(l<n){
            if(r-l-max_count<=k)
                ans=max(ans,r-l);
            if(r<n and r-l-max_count<=k){
                max_count=max(++cnt[a[r]],max_count);
                r++;
            }else{
                --cnt[a[l]];
                l++;
            }
        }
        return ans;
    }
};