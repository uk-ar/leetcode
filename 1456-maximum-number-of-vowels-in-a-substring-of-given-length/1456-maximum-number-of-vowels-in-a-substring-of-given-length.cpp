class Solution {
public:
    int maxVowels(string s, int k) {
        int c=0;
        string b="aiueo";
        unordered_set<char>se(b.begin(),b.end());
        for(int i=0;i<k;i++)
            if(se.count(s[i]))
                c++;
        int ans=c,N=s.size();
        for(int i=k;i<N;i++){
            if(se.count(s[i]))
                c++;
            if(se.count(s[i-k]))
                c--;
            ans=max(ans,c);
        }
        return ans;
    }
};