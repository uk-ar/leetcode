class Solution {
public:
    int shortestPath(vector<vector<int>>& g, int k) {
        deque<tuple<int,int,int,int>>q;//r,c,k,d
        q.push_back({0,0,k,0});
        int H=g.size(),W=g[0].size();
        vector<int>dr={0,-1,0,1};
        vector<int>dc={-1,0,1,0};
        vector<vector<int>>dist(H,vector<int>(W,INT_MAX));
        dist[0][0]=0;
        while(!q.empty()){
            auto [r,c,k,d]=q.front();q.pop_front();
            if(dist[r][c]<d)
                continue;
            dist[r][c]=d;
            for(int i=0;i<4;i++){                
                int nr=r+dr[i],nc=c+dc[i];
                //cout << r <<":"<<c <<" "<<nr <<":"<<nc<<endl;
                if(nr<0 or nr>=H or nc<0 or nc>=W or dist[nr][nc]<=d+1)
                    continue;
                if(g[nr][nc]==1 and k>0){
                    q.push_back({nr,nc,k-1,d+1});
                }else if(g[nr][nc]==0){
                    q.push_front({nr,nc,k,d+1});
                }
            }
        }
        /*for(auto &v:dist){
            for(auto e:v){
                cout << e <<" ";
            }
            cout <<endl;
        }*/
        if(dist[H-1][W-1]==INT_MAX)
            return -1;
        return dist[H-1][W-1];
    }
};