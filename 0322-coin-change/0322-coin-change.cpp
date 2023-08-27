class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N = coins.size();
        vector<vector<int>>dp(N+1,vector<int>(amount+1,INT_MAX));
        dp[0][0] = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= amount; j++){
                dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
                if(j <= amount - coins[i] && dp[i+1][j] != INT_MAX){
                    dp[i+1][j+coins[i]] = min(dp[i+1][j+coins[i]],dp[i+1][j]+1);
                }                
            }
        }
        if(dp[N][amount] == INT_MAX)
            return -1;
        return dp[N][amount];
    }
};