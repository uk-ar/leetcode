class Solution {
public:
    int maxNumberOfApples(vector<int>& w) {
        sort(w.begin(),w.end());
        int t=0,i=0,ans=0,N=w.size();
        while(i<N and t+w[i]<=5000){
            t+=w[i++];
            ans++;
        }
        return ans;
    }
};