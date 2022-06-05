class Solution {
public:
    vector<int> dr={-1,0,1,0};
    vector<int> dc={0,1,0,-1};
    int H,W;
    int dfs(int r,int c,vector<vector<int>>& m,vector<vector<int>>& len) {
        if(len[r][c]!=INT_MIN)
            return len[r][c];     
        len[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i],nc=c+dc[i];
            if(nr<0 or nr>=H or nc<0 or nc>=W)
                continue;
            if(m[nr][nc]<=m[r][c])
                continue;            
            len[r][c]=max(len[r][c],dfs(nr,nc,m,len)+1);
        }
        return len[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& m) {
        H=m.size(),W=m[0].size();
        vector<vector<int>>len(H,vector<int>(W,INT_MIN));
        int ans=1;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(len[i][j]==INT_MIN)
                    ans=max(ans,dfs(i,j,m,len));
            }
        }
        return ans;
    }
};