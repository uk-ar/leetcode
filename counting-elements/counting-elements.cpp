class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto &e:arr){
            m[e]++;
        }
        int ans=0;
        for(auto [k,v]:m){
            if(m.count(k+1))
                ans+=v;
        }
        return ans;
    }
};