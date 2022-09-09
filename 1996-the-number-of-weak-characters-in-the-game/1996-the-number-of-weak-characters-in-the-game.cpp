class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        sort(pro.begin(),pro.end(),[](auto &l,auto &r){
            if(l[0]==r[0])
                return l[1]<r[1];
            return l[0]>r[0];
        });
        int max_d=INT_MIN,ans=0;        
        for(auto v:pro){
            if(v[1]<max_d)
                ans++;
            max_d=max(max_d,v[1]);
        }
        return ans;
    }
};