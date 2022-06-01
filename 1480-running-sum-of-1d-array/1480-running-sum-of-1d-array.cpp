class Solution {
public:
    vector<int> runningSum(vector<int>& n) {
        vector<int> ans(n);
        ans[0]=n[0];
        for(int i=0;i+1<n.size();i++)
            ans[i+1]=ans[i]+n[i+1];
        return ans;
    }
};