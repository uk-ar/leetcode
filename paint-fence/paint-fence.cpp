class Solution {
public:
    int numWays(int n, int k) {
        if(n==1)
            return k;
        vector<vector<int>>dp(n,vector<int>(2));//dp[i][j]:ith day,j+1 consec
        dp[0][0]=k;
        for(int i=0;i+1<n;i++){
            dp[i+1][0]=dp[i][0]*(k-1)+dp[i][1]*(k-1);
            dp[i+1][1]=dp[i][0];
        }
        return dp[n-1][0]+dp[n-1][1];
    }
};