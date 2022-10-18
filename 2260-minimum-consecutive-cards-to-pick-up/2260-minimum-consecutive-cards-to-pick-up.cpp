class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        int N=c.size(),ans=INT_MAX;
        unordered_map<int,int>m;
        for(int i=0;i<N;i++){
            if(m.count(c[i]))
                ans=min(ans,i-m[c[i]]+1);
            //cout<< c[i] << i<<endl;
            m[c[i]]=i;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};