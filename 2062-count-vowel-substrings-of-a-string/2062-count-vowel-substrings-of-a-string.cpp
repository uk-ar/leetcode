class Solution {
public:    
    int vowels(unordered_map<char,int>&jm,string &s){
        int ans=0;
        for(char c:s)
            if(jm.count(c))
                ans++;
        return ans;
    }
    int countVowelSubstrings(string w) {
        int i=0,j=0,k=0,N=w.size(),ans=0;
        unordered_map<char,int>jm;
        unordered_map<char,int>km;
        string s="aiueo";
        for(i=0;i<N;i++){            
            while(j<N and jm.size()<5)
                jm[w[j++]]++;
            while(k<N and (km.size()<5 or (km.size()==5 and km.count(w[k]))))
                km[w[k++]]++;
            //cout <<i<<":"<<j<< ":"<<k<<":"<<jm.size() <<" ";
            //cout <<jm.size()<< ":" <<vowels(jm,s)<<endl;
            if(jm.size()==5 and vowels(jm,s)==5){                
                ans+=k-j+1;
            }
            if(--jm[w[i]]==0)
                jm.erase(w[i]);
            if(--km[w[i]]==0)
                km.erase(w[i]);
        }
        return ans;
    }
};