class Solution {
public:
    int H,W;
    vector<int>dr={0,-1,0,1};
    vector<int>dc={-1,0,1,0};
    bool dfs(vector<vector<char>>&b, string &w,int r,int c,vector<vector<bool>>&v,int i){
        //cout << r<<":"<<c<<":"<<b[r][c] <<":"<<i<< endl;
        v[r][c]=true;
        if(w.size()==i)
            return true;
        if(b[r][c]!=w[i]){
            v[r][c]=false;
            return false;            
        }
        if(w.size()-1==i)
            return true;
        for(int j=0;j<4;j++){
            int nr=r+dr[j],nc=c+dc[j];
            //cout << r<<":"<<c<<":"<<b[r][c] <<":"<<i<< " "<<nr<<":"<<nc<<endl;
            if(nr<0 or nr>=H or nc<0 or nc>=W or v[nr][nc])
                continue;
            if(dfs(b,w,nr,nc,v,i+1))
                return true;
        }
        v[r][c]=false;
        return false;
    }
    bool exist(vector<vector<char>>& b, string w) {
        H=b.size(),W=b[0].size();
        for(int i=0;i<H;i++)
            for(int j=0;j<W;j++){
                if(b[i][j]!=w[0])
                    continue;
                vector<vector<bool>>v(H,vector<bool>(W));
                if(dfs(b,w,i,j,v,0))
                    return true;
            }
        return false;
    }
};