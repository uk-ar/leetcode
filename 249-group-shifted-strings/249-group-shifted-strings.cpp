class Solution {
public:
    char shiftLetter(int shift,char c){
        return (c-'a'+shift+26)%26+'a';
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>>m;
        for(string &s:strings){
            int shift=s[0]-'a';//2
            string h;
            for(char c:s){
                h+=shiftLetter(-shift,c);
            }
            //cout << h<<endl;
            m[h].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto &[k,v]:m)
            ans.push_back(v);
        return ans;
    }
    long mod=((long)2<<61)-1;
    long mul(long t,long u){
        if(u==1)
            return t;
        long ans=mul((2*t)%mod,u/2);//9*2=
        if(u%2==0)
            return ans%mod;//5*3=5*2+5
        return (ans+t)%mod;
    }
    vector<vector<string>> groupStrings_rollinghash(vector<string>& strings) {
        unordered_map<int,vector<string>>m;        
        for(auto &s:strings){
            long t=0,n=s.size();
            for(int i=0;i+1<n;i++){
                //t=t*27%mod;
                t=mul(t,27)%mod;
                t=(t+(s[i+1]-s[i]+26)%26+1)%mod;
            }
            m[t].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto &[k,v]:m){
            ans.push_back(v);
        }
        return ans;
    }
};