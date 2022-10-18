class Solution {
public:
    int maximumSum(vector<int>& n) {
        int ans=-1;
        unordered_map<int,int>m;
        for(auto &e:n){
            int t=0,v=e;
            while(v){
                t+=v%10;
                v/=10;
            }
            //cout << t <<":"<< e <<endl;
            if(m.count(t))
                ans=max(ans,m[t]+e);
            m[t]=max(m[t],e);
        }
        return ans;
    }
};