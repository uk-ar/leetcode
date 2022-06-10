class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& m1, vector<vector<int>>& m2) {
        int H=m1.size(),W=m2[0].size(),W2=m1[0].size();
        vector<vector<int>>ans(H,vector<int>(W));
        //cout << H <<":"<<W<<":"<<W2<<endl;
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
                for(int k=0;k<W2;k++){
                    /*cout << i <<":"<< j <<":"<< k <<endl;
                    cout << ans[i][j] << endl;
                    cout << m1[i][k]  << endl;
                    cout << m2[k][j]  << endl;*/
                    ans[i][j]+=m1[i][k]*m2[k][j];
                }
        return ans;
    }
};