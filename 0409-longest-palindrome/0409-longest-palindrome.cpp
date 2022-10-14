class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>v(128);
        for(char &c:s)
            v[c]++;        
        bool odd=false;
        int ans=0;
        for(int i=0;i<128;i++){
            if(v[i]&1)
                odd=true;
            ans+=(v[i]>>1)<<1;
        }
        if(odd)
            return ans+1;
        return ans;
    }
};