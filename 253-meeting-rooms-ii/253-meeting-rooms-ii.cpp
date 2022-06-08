class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& in) {
        map<int,int>m;
        for(auto &v:in){
            m[v[0]]++;
            m[v[1]]--;
        }
        int ans=INT_MIN,t=0;
        for(auto &[k,v]:m){
            t+=v;
            //cout << k <<":"<<v <<":"<<t<<endl;
            ans=max(ans,t);
        }
        return ans;
    }
};