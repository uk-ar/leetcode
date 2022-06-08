class Solution {
public:
    bool isP(string s){
        //string t=s;
        //reverse(t.begin(),t.end());
        //return t==s;
        int l=0,r=s.size()-1;
        while(l<r and s[l]==s[r])
            l++,r--;
        return l>=r;
    }
    int removePalindromeSub(string s) {
        if(isP(s))
            return 1;
        return 2;
    }
};