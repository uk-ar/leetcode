class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int H = mat.size(),W = mat[0].size();
        vector<vector<int>>ans(H,vector<int>(W,INT_MAX));
        deque<pair<int,int>>q;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(mat[i][j] == 0){
                    q.push_back({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        vector<int>dr={0,-1,0,1};
        vector<int>dc={-1,0,1,0};
        while(q.size() > 0){
            int n = q.size();
            for(int i = 0; i < n ;i++){
                auto [r,c]=q.front();q.pop_front();
                for(int j = 0; j < 4; j++){
                    int nr = dr[j] + r, nc = dc[j] + c;
                    if(nr < 0 || nr >=H || nc < 0 || nc >= W){
                        continue;
                    }
                    if(ans[r][c] + 1 >= ans[nr][nc]){
                        continue;
                    }
                    ans[nr][nc] = ans[r][c]+1;
                    q.push_back({nr,nc});
                }
            }
        }
        return ans;
    }
};