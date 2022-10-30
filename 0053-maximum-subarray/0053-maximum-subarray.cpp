class Solution {
public:
    int maxSubArray_(vector<int>& n) {
        int mi=0,pre=0,ret=n[0];
        for(auto e:n){
            pre+=e;
            ret=max(ret,pre-mi);
            mi=min(mi,pre);
        }
        return ret;
    }
    int maxSubArray(vector<int>& n) {
        int ans=INT_MIN,cur=0;
        for(auto e:n){
            cur=max(e,cur+e);
            ans=max(ans,cur);
        }
        return ans;
    }
};