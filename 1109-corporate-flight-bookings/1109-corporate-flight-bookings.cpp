class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bs, int n) {
        vector<int>v(n+2);
        for(auto &b:bs){
            v[b[0]]+=b[2];
            v[b[1]+1]-=b[2];
        }
        vector<int>ans(n);
        for(int i=1;i<=n;i++){
            v[i]+=v[i-1];
            ans[i-1]=v[i];
        }
        return ans;
    }
};