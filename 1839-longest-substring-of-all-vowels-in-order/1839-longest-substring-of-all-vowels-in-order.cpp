class Solution {
public:
    int longestBeautifulSubstring(string w) {
        int l=0,r=0,ans=0,n=w.size(),c=0;
        //unordered_set<char>s;
        vector<int>s(128);        
        while(l<n){
            //if(s.size()==5)
            if(c==5)
                ans=max(ans,r-l);
            if(r<n and (l==r or w[r-1]<=w[r])){
                //s.emplace(w[r]);
                if(++s[w[r]]==1)
                    c++;
                r++;                
            }else{
                //s.clear();
                c=0;
                s['a']=0;
                s['e']=0;
                s['i']=0;
                s['o']=0;
                s['u']=0;
                l=r;
            }
        }
        return ans;
    }
};