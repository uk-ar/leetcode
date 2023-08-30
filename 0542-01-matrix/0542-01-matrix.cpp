class Solution {
public:
    int H,W;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        H = mat.size(), W = mat[0].size();
        // bfs
        deque<pair<int,int>>q;
        vector<vector<int>>ans(H,vector<int>(W,INT_MAX));
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(mat[i][j] == 0){
                    q.push_back({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        vector<int>dr = {0,-1,0,1};
        vector<int>dc = {-1,0,1,0};
        while(q.size() > 0){
            auto [r,c] = q.front();q.pop_front();
            for(int i = 0; i < 4; i++){
                int nr = dr[i] + r, nc = dc[i] + c;
                if(nr < 0 || nr >= H || nc < 0 || nc >= W){
                    continue;
                }
                if(ans[nr][nc] <= ans[r][c]+1){
                    continue;
                }
                ans[nr][nc] = ans[r][c]+1;
                q.push_back({nr,nc});
            }
        }
        return ans;
    }
};