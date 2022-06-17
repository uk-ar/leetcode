class Solution {
public:
    using vi=vector<int>;
    int maximalRectangle(vector<vector<char>>& m) {
        int H=m.size(),W=m[0].size();
        vector<vi>dp(H,vi(W));
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(i==0)
                    dp[i][j]=m[i][j]-'0';
                else if(m[i][j]=='0')
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+1;
            }
        }
        int ans=0;
        for(int i=0;i<H;i++){
            vector<vi>st;
            dp[i].push_back(0);
            for(int j=0;j<W+1;j++){
                vector<int>v={dp[i][j],j};
                while(!st.empty() and st.back()[0]>dp[i][j]){
                    ans=max(ans,st.back()[0]*(j-st.back()[1]));
                    v[1]=st.back()[1];
                    st.pop_back();
                }
                st.push_back(v);
                cout << dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};