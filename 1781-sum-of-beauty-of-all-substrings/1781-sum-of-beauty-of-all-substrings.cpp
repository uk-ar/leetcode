class Solution {
public:
    int min_e(unordered_map<int,int>&m){
        int ans=INT_MAX;
        for(auto &p:m)
            ans=min(ans,p.second);
        return ans;
    }
    int beautySum(string s) {
        int N=s.size(),ans=0;
        for(int i=0;i<N;i++){
            unordered_map<int,int>m;            
            int ma=0;
            for(int j=i;j<N;j++){
                ma=max(ma,++m[s[j]]);
                ans+=ma-min_e(m);
                //cout << i << ":"<<j <<":"<<ma<<endl;
            }
        }
        return ans;
    }
};