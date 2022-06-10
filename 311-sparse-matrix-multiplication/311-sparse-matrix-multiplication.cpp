class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& m1, vector<vector<int>>& m2) {
        int H=m1.size(),W=m2[0].size(),W2=m1[0].size();
        vector<vector<int>>ans(H,vector<int>(W));
        for(int i=0;i<H;i++){
            for(int k=0;k<W2;k++){
                if(m1[i][k]==0)
                    continue;
                for(int j=0;j<W;j++){                
                    ans[i][j]+=m1[i][k]*m2[k][j];
                }
            }
        }
        return ans;
    }
};