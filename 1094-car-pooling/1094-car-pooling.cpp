class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //map<int,int>m;
        vector<int> m(1000+1);
        for(auto &v:trips){
            m[v[1]]+=v[0];
            m[v[2]]-=v[0];
        }
        int t=0;
        for(int i=0;i<=1000;i++){
            t+=m[i];
            if(t>capacity)
                return false;
        }
        return true;
    }
};