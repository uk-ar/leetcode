class Solution {
public:
    int maxResult(vector<int>& n, int k) {
        int N=n.size();
        deque<pair<int,int>>q;//value,index
        q.push_back({n[0],0});
        for(int i=1;i<N;i++){
            //while()//lim to k
            while(!q.empty() and q.front().second<i-k)//{1:0}<1-2=-1
                q.pop_front();
            int t=q.front().first+n[i];//
            while(!q.empty() and q.back().first<t)
                q.pop_back();
            q.push_back({t,i});
        }
        return q.back().first;
    }
};