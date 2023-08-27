class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs O(N) O(1)
        int H = grid.size(),W = grid[0].size();
        deque<pair<int,int>>q;
        int ones = 0;
        for(int i = 0; i < H ;i++){
            for(int j = 0; j < W ;j++){
                // collect rotten and fresh
                if(grid[i][j] == 2){
                    q.push_back({i,j});
                }else if(grid[i][j] == 1){
                    ones++;
                }
            }
        }
        vector<int>dr = {0,-1,0,1};
        vector<int>dc = {-1,0,1,0};
        if(ones == 0)
            return 0;
        int ans = -1;
        while(q.size() > 0){
            int n = q.size();
            while(n--){
                auto [r,c] = q.front();q.pop_front();
                for(int i = 0; i < 4 ; i++){
                    int nr = dr[i]+r, nc = dc[i]+c;
                    if(nr < 0 || nr >= H || nc < 0 || nc >= W){
                        continue;
                    }
                    if(grid[nr][nc] != 1){
                        continue;
                    }
                    q.push_back({nr,nc});
                    grid[nr][nc] = 2;
                    ones--;
                }
            }
            ans++;
        }
        if(ones == 0)
            return ans;
        return -1;
    }
};