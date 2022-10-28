class Solution {
public:
    int uniqueLetterString(string s) {
        unordered_map<int,int>last;
        int N=s.size();
        vector<int>l(N);
        for(int i=0;i<N;i++){
            l[i]=i+1;
            if(last.count(s[i]))
                l[i]=i-last[s[i]];
            last[s[i]]=i;
        }
        last.clear();
        vector<int>r(N);
        for(int i=N-1;i>=0;i--){
            r[i]=N-i;
            if(last.count(s[i]))
                r[i]=last[s[i]]-i;
            last[s[i]]=i;
        }
        long ans=0;
        for(int i=0;i<N;i++){
            ans+=l[i]*r[i];
        }
        return ans;
    }
};