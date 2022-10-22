class Solution {
public:
    int nearestExit(vector<vector<char>>& m, vector<int>& ent) {
        int H=m.size(),W=m[0].size();
        deque<tuple<int,int,int>>q;
        q.push_back({ent[0],ent[1],0});
        vector<int>dr({0,1,0,-1});
        vector<int>dc({1,0,-1,0});
        while(!q.empty()){
            auto [r,c,d]=q.front();q.pop_front();            
            if(d!=0 and (r==0 or c==0 or r==H-1 or c==W-1))
                return d;
            m[r][c]='+';
            for(int i=0;i<4;i++){
                int nr=r+dr[i],nc=c+dc[i];
                if(nr<0 or nr>=H or nc<0 or nc>=W or m[nr][nc]=='+')
                    continue;
                q.push_back({nr,nc,d+1});
                m[nr][nc]='+';
            }
        }
        return -1;
    }
};