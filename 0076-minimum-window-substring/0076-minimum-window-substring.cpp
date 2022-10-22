class Solution {
public:
    int check(unordered_map<char,int>&m){
        int ans=0;
        for(auto &[c,i]:m){
            if(i>0)
                ans++;
        }
        return ans;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        unordered_set<char>se(t.begin(),t.end());
        int N=s.size();
        for(int i=0;i<t.size();i++)
            m[t[i]]++;
        int l=0,r=0,mi=INT_MAX;
        string ans;
        while(l<N){
            //cout << l << ":" << r <<" "<<m.size()<<":"<<mi<<ans<<endl;
            /*for(auto &p:m)
                cout << p.first <<":" << p.second <<" ";
            cout <<endl;*/
            if(check(m)==0 and r-l<=mi){
                mi=r-l;
                ans=s.substr(l,r-l);
            }
            if(r<N and check(m)>0){//
                if(se.count(s[r]) and --m[s[r]]==0)
                    m.erase(s[r]);
                r++;
            }else{
                if(se.count(s[l]) and ++m[s[l]]==0)
                    m.erase(s[l]);
                l++;
            }
        }
        if(mi==INT_MAX)
            return "";
        return ans;
    }
};