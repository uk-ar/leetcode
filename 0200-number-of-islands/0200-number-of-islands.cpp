class Solution {
public:
    int H,W;
    vector<int>dr={0,-1,0,1};
    vector<int>dc={-1,0,1,0};
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        for(int i = 0; i < 4; i++){
            int nr = dr[i] + r, nc = dc[i] + c;
            if(nr < 0 || nr >= H || nc < 0 || nc >= W)
                continue;
            if(grid[nr][nc] == '0')
                continue;
            dfs(grid,nr,nc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        H = grid.size();
        W = grid[0].size();
        int count=0;
        for(int i = 0; i < H ; i++){
            for(int j = 0; j < W ; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};