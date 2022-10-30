class Solution {
public:
    int getFood(vector<vector<char>>& g) {
        int H=g.size(),W=g[0].size();
        deque<pair<int,int>>q;
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++)
                if(g[i][j]=='*')
                    q.push_back({i,j});
        
        vector<int>dr={0,1,0,-1};
        vector<int>dc={1,0,-1,0};
        vector<vector<int>>dist(H,vector<int>(W,INT_MAX));
        dist[q.front().first][q.front().second]=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto [r,c]=q.front();q.pop_front();
                //cout << r <<":"<<c<<endl;              
                if(g[r][c]=='#')
                    return dist[r][c];
                g[r][c]='X';
                for(int i=0;i<4;i++){
                    int nr=r+dr[i],nc=c+dc[i];
                    //cout << r <<":"<<c<<" "<<nr<<":"<<nc<<endl;                    
                    if(nr<0 or nr>=H or nc<0 or nc>=W or g[nr][nc]=='X')
                        continue;
                    if(dist[nr][nc]<=dist[r][c]+1)
                        continue;
                    dist[nr][nc]=dist[r][c]+1;
                    q.push_back({nr,nc});
                }
            }
        }
        return -1;
    }
};