class Solution {
public:
    vector<int> answerQueries(vector<int>& n, vector<int>& q) {
        sort(n.begin(),n.end());
        int N=n.size();
        for(int i=0;i+1<N;i++)
            n[i+1]+=n[i];
        vector<int>ans;
        for(int e:q){
            ans.push_back(upper_bound(n.begin(),n.end(),e)-n.begin());
        }
        return ans;
    }
};