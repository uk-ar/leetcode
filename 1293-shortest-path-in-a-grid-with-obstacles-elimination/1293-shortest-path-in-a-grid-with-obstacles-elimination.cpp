class Solution {
public:
    int shortestPath(vector<vector<int>>& g, int k) {
        int H=g.size(),W=g[0].size();
        deque<tuple<int,int,int,int>>q;
        q.push_back({0,0,0,k});//r,c,dist,k
        vector<vector<int>>dist(H,vector<int>(W,INT_MAX));
        vector<int>dr={0,1,0,-1};
        vector<int>dc={1,0,-1,0};
        while(!q.empty()){
            auto [r,c,d,k]=q.front();q.pop_front();
            //cout << r <<":"<<c<<":"<<d<<":"<<k<<endl;
            if(dist[r][c]<=d)
                continue;
            dist[r][c]=d;
            for(int i=0;i<4;i++){
                int nr=r+dr[i],nc=c+dc[i];                
                if(nr<0 or nr>=H or nc<0 or nc>=W)
                    continue;
                if(g[nr][nc]==1 and k==0)
                    continue;
                if(g[nr][nc]==1)
                    q.push_back({nr,nc,d+1,k-1});
                else
                    q.push_front({nr,nc,d+1,k});
            }
        }
        if(dist[H-1][W-1]==INT_MAX)
            return -1;
        return dist[H-1][W-1];
    }
};