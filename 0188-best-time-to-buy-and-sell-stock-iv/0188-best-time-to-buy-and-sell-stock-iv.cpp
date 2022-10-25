class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
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
                /*dp[i+1][j][true]=dp[i][j][true];
                if(j+1<k and dp[i][j+1][false]!=INT_MIN)
                    dp[i+1][j][true]=max(dp[i+1][j][true],dp[i][j+1][false]-p[i]);
                dp[i+1][j][false]=dp[i][j][false];
                dp[i+1][j][false]=max(dp[i+1][j][false],dp[i+1][j][true]+p[i]);*/
            }
        }
        //int ans=0;
        /*for(int j=0;j<=k;j++){
            ans=max(ans,dp[N][j][false]);
            ans=max(ans,dp[N][j][true]);
        }*/
        return ans;
        //return dp[N][0][false];
    }
};