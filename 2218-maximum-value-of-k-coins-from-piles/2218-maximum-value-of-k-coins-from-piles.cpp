class Solution {
public:
    int N;
    unordered_map<int,unordered_map<int,int>>memo;
    int dp(vector<vector<int>>& p, int k,int i) {
        //cout << k << ":"<<i<<endl;
        if(i==N)
            return 0;
        if(memo[k].count(i))
            return memo[k][i];
        int ans=0;
        int t=0;
        for(int j=0;j<=k and j<=p[i].size();j++){
            ans=max(ans,dp(p,k-j,i+1)+t);
            if(j<k and j<p[i].size())
                t+=p[i][j];
        }
        return memo[k][i]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
        N=p.size();
        return dp(p,k,0);
    }
    int maxValueOfCoins_(vector<vector<int>>& p, int k) {
        int N=p.size(),ans=0;
        vector<vector<int>>dp(N+1,vector<int>(k+1));
        for(int i=0;i<N;i++){
            for(int from=0;from<=k;from++){
                int t=dp[i][from];
                for(int cnt=0;from+cnt<=k and cnt<=p[i].size();cnt++){                    
                    int to=from+cnt;
                    dp[i+1][to]=max(dp[i+1][to],t);
                    //cout << i <<":"<< from <<":"<< cnt <<":"<<to<<":"<< dp[i+1][to]<<endl;
                    ans=max(ans,dp[i+1][to]);
                    if(cnt<p[i].size())
                        t+=p[i][cnt];
                }         
            }
        }
        return ans;
    }
};