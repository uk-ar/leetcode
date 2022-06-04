class Solution {
public:
    int N;
    void solve(vector<string> &p,int r,int c,int add,int sub,vector<vector<string>> &ans){
        if(r==N){
            ans.push_back(p);
            return;
        }            
        for(int i=0;i<N;i++){
            if(((c>>i)&1) or ((add>>(r+i))&1) or ((sub>>(r-i+N))&1))
                continue;
            string t(N,'.');
            t[i]='Q';
            p.push_back(t);
            solve(p,r+1,c|(1<<i),add|(1<<(r+i)),sub|(1<<(r-i+N)),ans);
            p.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<vector<string>> ans;
        vector<string> p;
        solve(p,0,0,0,0,ans);
        return ans;
    }
};