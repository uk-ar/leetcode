class Solution {
public:
    void backtrack(vector<int>& can, int t,int i,vector<int>&p,vector<vector<int>>&ans) {
        if(t==0){
            ans.push_back(p);
            return;
        }
        if(can.size()==i)
            return;
        int j;
        for(j=0;0<=t;j++){//5
            backtrack(can,t,i+1,p,ans);
            p.push_back(can[i]);
            t-=can[i];
        }
        for(int k=0;k<j;k++)
            p.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        vector<vector<int>> ans;
        vector<int> p;
        backtrack(can,t,0,p,ans);
        return ans;
    }
};