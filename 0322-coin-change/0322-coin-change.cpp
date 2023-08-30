class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp O(N*M) O(N*M)
        int N=coins.size();
        vector<vector<int>>dp(N+1,vector<int>(amount+1,INT_MAX));
        dp[0][0] = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= amount; j++){
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
                if(j - coins[i] >= 0 && dp[i+1][j - coins[i]] != INT_MAX)
                    dp[i+1][j] = min(dp[i+1][j - coins[i]] + 1,dp[i+1][j]);
                //cout << dp[i+1][j] << endl;
            }
        }
        if(dp[N][amount] == INT_MAX)
            return -1;
        return dp[N][amount];
    }
};