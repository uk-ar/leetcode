class Solution {
public:
    vector<int> findErrorNums(vector<int>& n) {
        vector<int>ans(2);
        unordered_set<int>s;
        int sum=0,N=n.size();
        for(int e:n){
            if(s.count(e))
                ans[0]=e;
            s.insert(e);
            sum+=e;
        }
        ans[1]=(N+1)*N/2-(sum-ans[0]);
        return ans;
    }
};