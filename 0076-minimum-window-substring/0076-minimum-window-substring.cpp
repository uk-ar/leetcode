class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        unordered_set<char>se(t.begin(),t.end());
        int N=s.size(),c=0;
        for(int i=0;i<t.size();i++)
            if(++m[t[i]]==1)
                c++;
        int l=0,r=0,mi=INT_MAX;
        string ans;
        while(l<N){
            //cout << l << ":" << r <<" "<<m.size()<<":"<<mi<<ans<<endl;
            /*for(auto &p:m)
                cout << p.first <<":" << p.second <<" ";
            cout <<endl;*/
            if(c==0 and r-l<=mi){
                mi=r-l;
                ans=s.substr(l,r-l);
            }
            if(r<N and c>0){//
                if(se.count(s[r]) and --m[s[r]]==0)
                    c--;
                r++;
            }else{
                if(se.count(s[l]) and ++m[s[l]]==1)
                    c++;
                l++;
            }
        }
        if(mi==INT_MAX)
            return "";
        return ans;
    }
};