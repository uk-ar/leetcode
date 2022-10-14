class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0,m_e=p[0],n=p.size();
        for(int i=1;i<n;i++){
            ans=max(ans,p[i]-m_e);
            m_e=min(m_e,p[i]);
        }
        return ans;
    }
};