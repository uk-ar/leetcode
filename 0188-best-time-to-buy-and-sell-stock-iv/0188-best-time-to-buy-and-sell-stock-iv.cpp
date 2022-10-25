class Solution {
public:
    int N;
    unordered_map<int,unordered_map<int,unordered_map<bool,int>>>memo;
    int dp(int k,vector<int>& p,int i,bool holding) {
        if(i==N)
            return 0;
        if(memo[k][i].count(holding))
            return memo[k][i][holding];
        int ans=dp(k,p,i+1,holding);
        //buy
        if(!holding and k-1>=0)
            ans=max(ans,dp(k-1,p,i+1,true)-p[i]);
        //sell
        if(holding)
            ans=max(ans,dp(k,p,i+1,false)+p[i]);
        return memo[k][i][holding]=ans;
    }
    int maxProfit(int k, vector<int>& p) {
        N=p.size();
        return dp(k,p,0,false);
    }
    int maxProfit_(int k, vector<int>& p) {
        int N=p.size();
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(k+1,vector<int>(2,INT_MIN)));
        dp[0][k][0]=0;
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<=k;j++){
                if(dp[i][j][1]!=INT_MIN){
                    dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][1]);
                    dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][1]+p[i]);
                }
                if(dp[i][j][0]!=INT_MIN)
                    dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][0]);
                if(dp[i][j][0]!=INT_MIN and j-1>=0)
                    dp[i+1][j-1][1]=max(dp[i+1][j-1][1],dp[i][j][0]-p[i]);
                ans=max(ans,dp[i+1][j][1]);
                ans=max(ans,dp[i+1][j][0]);
            }
        }
        return ans;
    }
};