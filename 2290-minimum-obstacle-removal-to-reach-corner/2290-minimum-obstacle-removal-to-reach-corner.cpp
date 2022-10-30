class Solution {
public:
    int minimumObstacles(vector<vector<int>>& g) {
        int H=g.size(),W=g[0].size();
        vector<vector<bool>>vis(H,vector<bool>(W));
        deque<tuple<int,int,int>>q;
        q.push_back({0,0,0});//r,c,ob
        vector<int>dr={0,1,0,-1};
        vector<int>dc={1,0,-1,0};
        vis[0][0]=true;
        while(!q.empty()){
            auto [r,c,ob]=q.front();q.pop_front();
            if(r==H-1 and c==W-1)
                return ob;
            
            for(int i=0;i<4;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr<0 or nr>=H or nc<0 or nc>=W or vis[nr][nc])
                    continue;
                vis[nr][nc]=true;
                if(g[nr][nc]==0){
                    q.push_front({nr,nc,ob});
                }else{
                    q.push_back({nr,nc,ob+1});
                }
            }
        }
        return -1;
    }
};