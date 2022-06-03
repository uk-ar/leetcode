class Solution {
public:
    string findReplaceString(string s, vector<int>& in, vector<string>& src, vector<string>& dst) {
        int N=in.size();
        vector<vector<int>>m;
        for(int i=0;i<N;i++)
            m.push_back({in[i],i});
        sort(m.begin(),m.end(),greater<vector<int>>());
        for(int i=0;i<N;i++){
            int j=m[i][1];
            if(in[j]+src[j].size()<=s.size() and s.compare(in[j],src[j].size(),src[j])==0)
                s.replace(in[j],src[j].size(),dst[j]);
        }
        return s;
    }
};