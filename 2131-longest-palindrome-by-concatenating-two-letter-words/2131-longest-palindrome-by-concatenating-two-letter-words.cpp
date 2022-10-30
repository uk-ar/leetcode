class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>m;
        int ans=0;
        for(string &s:words){
            string t={s[1],s[0]};
            if(m.count(t)){
                if(--m[t]==0)
                    m.erase(t);
                ans+=4;
            }else{
                m[s]++;
            }     
            //cout << s << ans<<endl;
        }
        for(auto &[s,_]:m){
            if(s[0]==s[1])
                return ans+=2;
        }
        return ans;
    }
};