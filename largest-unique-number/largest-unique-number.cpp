class Solution {
public:
    int largestUniqueNumber(vector<int>& n) {
        unordered_map<int,int>m;
        for(auto &c:n)
            m[c]++;
        int ans=-1;
        for(auto &[k,v]:m){
            if(v==1)
                ans=max(ans,k);
        }
        return ans;
    }
};