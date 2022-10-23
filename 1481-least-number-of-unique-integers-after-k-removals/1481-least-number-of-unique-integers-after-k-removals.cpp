class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& a, int k) {
        unordered_map<int,int>m;
        for(auto &e:a)
            m[e]++;
        vector<pair<int,int>>fe;
        for(auto &[e,f]:m)
            fe.push_back({f,e});
        sort(fe.begin(),fe.end());
        int N=fe.size(),ans=0;
        for(int i=0;i<N;i++){
            int act=min(fe[i].first,k);
            fe[i].first-=act;
            k-=act;                        
            if(fe[i].first>0)
                ans++;
        }
        return ans;
    }
};