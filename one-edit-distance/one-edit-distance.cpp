class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size()>t.size())
            swap(s,t);
        int ns=s.size(),nt=t.size(),si=0,ti=0;
        if(ns+1<nt)
            return false;      
        bool f=false;
        while(si<ns and ti<nt){
            if(s[si]==t[ti]){
                si++;ti++;
                continue;
            }else if(f==false and ns==nt){
                f=true;
                si++;
                ti++;
            }else if(f==false and ns<nt){
                f=true;
                ti++;
            }else{
                return false;
            }
        }
        if(ns!=nt and !f)
            return true;
        return f;
    }
};