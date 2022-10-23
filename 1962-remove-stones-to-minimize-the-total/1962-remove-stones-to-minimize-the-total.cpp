class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
        priority_queue<int>q(p.begin(),p.end());
        int s=0;
        for(auto &e:p)
            s+=e;
        for(int i=0;i<k;i++){
            int n=q.top();q.pop();
            int r=n/2;
            q.push(n-r);
            s-=r;
        }
        return s;
    }
};