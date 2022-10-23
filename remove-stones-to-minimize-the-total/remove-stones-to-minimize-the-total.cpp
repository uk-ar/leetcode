class Solution {
public:
    int minStoneSum(vector<int>& p, int k) {
        priority_queue<int>q(p.begin(),p.end());
        int s=0;
        for(int i=0;i<k;i++){
            int n=q.top();q.pop();
            q.push((n+1)/2);
        }
        while(!q.empty()){
            s+=q.top();
            q.pop();
        }
        return s;
    }
};