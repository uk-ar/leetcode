class Solution {
public:
    int vari(string &s,char a,char b) {
        int ans=0,cur=0;
        bool has_b=false,first_b=false;
        for(auto c:s){            
            cur+=c==a;
            if(c==b){
                has_b=true;
                if(first_b and cur>=0)//2nd b
                    first_b=false;
                else if(--cur<0){//3rd b later
                    first_b=true;
                    cur=-1;
                }
            }
            if(has_b)
                ans=max(ans,cur);
        }
        return ans;
    }
    int largestVariance(string s) {
        int ans=0;
        for(char mi='a';mi<='z';mi++){
            for(char ma='a';ma<='z';ma++){
                ans=max(ans,vari(s,mi,ma));
            }
        }
        //"abcde"
        //"aababbb"
        return ans;
    }    
    int largestVariance_(string s) {
        int N=s.size(),ans=0;
        for(int i=0;i<N;i++){
            unordered_map<char,int>m;
            map<int,int>f;
            for(int j=i;j<N;j++){
                if(--f[m[s[j]]]<=0)
                    f.erase(m[s[j]]);
                m[s[j]]++;
                f[m[s[j]]]++;
                ans=max(ans,(*f.rbegin()).first-(*f.begin()).first);
            }
        }
        return ans;
    }
};