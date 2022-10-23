class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string u,v;
        for(char c:s){
            if(c=='#'){
                if(!u.empty()){
                    u.pop_back();
                }
            }else
                u+=c;
        }
        for(char c:t){
            if(c=='#'){
                if(!v.empty()){
                    v.pop_back();
                }
            }else
                v+=c;
        }        
        return u==v;
    }
};