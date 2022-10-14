class Solution {
public:
    int longestBeautifulSubstring(string w) {
        int l=0,r=0,ans=0,n=w.size();
        unordered_set<char>s;
        while(l<n){
            if(s.size()==5)
                ans=max(ans,r-l);
            if(r<n and (l==r or w[r-1]<=w[r])){
                s.emplace(w[r]);
                r++;                
            }else{
                s.clear();
                l=r;
            }
        }
        return ans;
    }
};