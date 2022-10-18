class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        int N=g.size();
        unordered_map<string,int>m;
        for(int i=0;i<N;i++){
            string t;
            for(int j=0;j<N;j++){
                t+=to_string(g[i][j])+" ";
            }
            m[t]++;
        }
        int ans=0;
        for(int i=0;i<N;i++){
            string t;
            for(int j=0;j<N;j++){
                t+=to_string(g[j][i])+" ";
            }
            ans+=m[t];
        }
        return ans;
    }
};