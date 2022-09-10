vector<vector<int>> dp(1000+1,vector<int>(2*100+1,INT_MIN>>2));
class Solution {
public:
    int maxProfit(int K, vector<int>& P) {
        dp[0][0]=0;
        int N = P.size();
        for(int i=0;i<N;i++){
            for(int k=0;k<2*K+1;k++){
                if(k==0){
                    dp[i+1][0] = dp[i][0];
                    continue;
                }
                if(k%2==1)
                    dp[i+1][k] = max(dp[i][k],dp[i][k-1]-P[i]);
                else
                    dp[i+1][k] = max(dp[i][k],dp[i][k-1]+P[i]);
                //cout << dp[i+1][k] << " ";
            }
            //cout << endl;
        }
        //cout << endl;
        return *max_element(dp[N].begin(),dp[N].begin()+2*K+1);
    }
};