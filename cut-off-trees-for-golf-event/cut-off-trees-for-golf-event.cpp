class Solution {
public:
    int H,W;
    vector<int>dr={0,-1,0,1};
    vector<int>dc={-1,0,1,0};
    vector<vector<int>>d;//(H,vector<int>(W,INT_MAX));
    int bfs(int sr,int sc,int er,int ec,vector<vector<int>>& f) {
        deque<pair<int,int>>q;
        d.assign(H,vector<int>(W,INT_MAX));
        q.push_back({sr,sc});
        d[sr][sc]=0;
        //cout << sr <<":"<< sc <<"->"<<er<<":"<<ec<<endl;
        while(!q.empty()){
            auto [r,c]=q.front();q.pop_front();
            if(r==er and c==ec)
                return d[er][ec];
            for(int i=0;i<4;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr<0 or nr>=H or nc<0 or nc>=W)
                    continue;
                if(f[nr][nc]==0)
                    continue;
                if(d[nr][nc]<=d[r][c]+1)
                    continue;
                //cout << r<<":"<< c <<">>"<<nr<<":"<<nc<<endl;
                d[nr][nc]=d[r][c]+1;
                q.push_back({nr,nc});
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& f) {
        H=f.size(),W=f[0].size();
        map<int,pair<int,int>>m;
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++){
                if(f[i][j]>1)
                    m[f[i][j]]={i,j};
            }
        int r=0,c=0,ans=0;
        for(auto &[k,v]:m){
            auto &[nr,nc]=v;
            int d=bfs(r,c,nr,nc,f);
            //int d=0;
            if(d==-1)
                return -1;
            ans+=d;
            r=nr;
            c=nc;
        }
        return ans;
    }
};