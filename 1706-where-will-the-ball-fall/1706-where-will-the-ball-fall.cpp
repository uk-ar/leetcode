class Solution {
public:
    vector<int> findBall(vector<vector<int>>& g) {
        int H=g.size(),W=g[0].size();
        vector<vector<int>>v(H+1,vector<int>(W,-1));
        for(int i=0;i<W;i++)
            v[0][i]=i;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                //cout << g[i][j] << " ";
                if(j+1<W  and g[i][j]==1 and g[i][j+1]==1)
                    v[i+1][j+1]=v[i][j];
                if(j-1>=0 and g[i][j-1]==-1 and g[i][j]==-1)
                    v[i+1][j-1]=v[i][j];
            }
            //cout << endl;
        }
        for(auto &e:v){
            for(auto f:e)
                cout << f <<" ";
            cout<<endl;
        }
        vector<int>ans(W,-1);
        for(int i=0;i<W;i++)
            if(v[H][i]!=-1)
                ans[v[H][i]]=i;
        return ans;
        //return v[H];
    }
};