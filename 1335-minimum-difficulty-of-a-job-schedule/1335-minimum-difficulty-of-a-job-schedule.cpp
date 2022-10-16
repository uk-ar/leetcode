class Solution {
public:
    int minDifficulty(vector<int>& j, int d) {
        int N=j.size();
        vector<vector<int>>dp(d+1,vector<int>(N+1,INT_MAX));
        dp[0][0]=0;//total
        for(int i=0;i<d;i++){//ith day
            for(int from=0;from<N;from++){
                //cout << i << ":" << from << ":" <<endl;
                if(dp[i][from]==INT_MAX)
                    continue;
                int m=j[from];
                for(int to=from+1;to<=N;to++){//
                    //cout << i << ":" << from << ":" << to <<endl;
                    m=max(m,j[to-1]);
                    dp[i+1][to]=min(dp[i+1][to],dp[i][from]+m);
                }
            }
        }
        if(dp[d][N]==INT_MAX)
            return -1;
        return dp[d][N];
    }
};