class Solution {
public:
    int numDecodings(string s) {
        int N=s.size();
        vector<int>dp(N+1);
        dp[0]=1;
        for(int i=0;i<N;i++){
            if(s[i]!='0')
                dp[i+1]+=dp[i];
            if(i+1==N)
                continue;
            if((s[i]=='2' and s[i+1]<='6') or s[i]=='1')
                dp[i+2]+=dp[i];
        }
        return dp[N];
    }
};