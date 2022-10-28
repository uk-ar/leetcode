class Solution {
public:
    long long appealSum(string s) {
        unordered_map<char,int>last;
        long N=s.size(),ans=0;
        for(int i=0;i<N;i++){
            int l=i+1;
            if(last.count(s[i])){
                l=i-last[s[i]];
            }
            last[s[i]]=i;
            ans=ans+(long)l*(N-i);
            //cout << i <<":"<< l<<":"<< s[i]<<":"<<ans<<endl;
        }
        return ans;
    }
};