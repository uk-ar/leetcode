class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        if(n==0)
            return t.size();
        int N=t.size();
        unordered_map<int,int>m;
        for(int i=0;i<N;i++)
            m[t[i]]++;
        priority_queue<int>q;
        for(auto [_,f]:m)
            q.push(f);
        int ans=0;
        while(!q.empty()){
            priority_queue<int>t;
            for(int i=0;i<n+1;i++){
                if(!q.empty()){
                    //cout << i << ":" << ans <<":" << q.top() <<endl;
                    if(q.top()!=1)
                        t.push(q.top()-1);
                    q.pop();    
                }else if(t.empty()){
                    return ans;
                }
                ans++;                
            }
            while(!t.empty()){
                q.push(t.top());
                t.pop();
            }
        }
        return ans;
    }
};