class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0,l=0,n=s.size(),ans=0,m_count=0;
        vector<int>v(128);
        while(l<n){
            if(r-l-m_count<=k)
                ans=max(ans,r-l);
            if(r<n and r-l-m_count<=k){//A   
                m_count=max(++v[s[r]],m_count);
                r++;
            }else{
                v[s[l]]--;
                l++;
            }
            
        }
        //cout<<endl;
        return ans;
    }
};