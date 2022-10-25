class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
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