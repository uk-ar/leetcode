class Solution {
public:
    string getHint(string s, string g) {
        int N=s.size(),b=0,co=0;
        unordered_map<char,int>m;
        string ng;
        for(int i=0;i<N;i++){
            if(s[i]==g[i])
                b++;
            else{
                m[s[i]]++;
                ng+=g[i];
            }
        }
        for(auto c:ng){
            if(m.count(c)){
                co++;
                if(--m[c]==0)
                    m.erase(c);
            }
        }
        return to_string(b)+"A"+to_string(co)+"B";
    }
};