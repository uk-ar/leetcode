class Solution {
public:
    int N;
    void comb(vector<int>& can,int t,int i,vector<int>&path,vector<vector<int>>&ans) {
        if(t==0){
            ans.push_back(path);
            return;
        }
        if(i==N)
            return;
        int j;
        for(j=0;j*can[i]<=t;j++){
            for(int k=0;k<j;k++)
                path.push_back(can[i]);
            comb(can,t-j*can[i],i+1,path,ans);
            for(int k=0;k<j;k++)
                path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        N=can.size();
        vector<int>path;
        vector<vector<int>>ans;
        comb(can,target,0,path,ans);
        return ans;
    }
};